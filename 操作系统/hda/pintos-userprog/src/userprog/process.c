#include "userprog/process.h"
#include <debug.h>
#include <inttypes.h>
#include <round.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "userprog/gdt.h"
#include "userprog/pagedir.h"
#include "userprog/tss.h"
#include "filesys/directory.h"
#include "filesys/file.h"
#include "filesys/filesys.h"
#include "threads/flags.h"
#include "threads/init.h"
#include "threads/interrupt.h"
#include "threads/malloc.h"
#include "threads/palloc.h"
#include "threads/synch.h"
#include "threads/thread.h"
#include "threads/vaddr.h"
// Initialize a global file system lock for file system calls
struct lock filesys_lock;

// Initialize a new file descriptor table
void init_fdtable(file_descriptor_list_t* fdlist) {
  if (fdlist == NULL) {
    return;
  }
  list_init(fdlist);
}

// Find a file descriptor in the file descriptor table
file_descriptor_t* find_fd(file_descriptor_list_t* fdlist, int fd) {
  if (fdlist == NULL) {
    return NULL;
  }
  struct list_elem* e;
  for (e = list_begin(fdlist); e != list_end(fdlist); e = list_next(e)) {
    struct file_descriptor* curr_fd = list_entry(e, struct file_descriptor, elem);
    if (curr_fd->fd == fd) {
      return curr_fd;
    }
  }
  return NULL;
}

// Find a file name in the file descriptor table
file_descriptor_t* find_filename(file_descriptor_list_t* fdlist, const char* name) {
  if (fdlist == NULL || name == NULL) {
    return NULL;
  }
  struct list_elem* e;
  for (e = list_begin(fdlist); e != list_end(fdlist); e = list_next(e)) {
    struct file_descriptor* curr_fd = list_entry(e, struct file_descriptor, elem);
    if (strcmp(curr_fd->file_name, name) == 0) {
      return curr_fd;
    }
  }
  return NULL;
}

static struct semaphore temporary;
static thread_func start_process NO_RETURN;
static thread_func start_pthread NO_RETURN;
static bool load(const char* file_name, void (**eip)(void), void** esp);
bool setup_thread(void (**eip)(void), void** esp);
// Add a file descriptor to the file descriptor table
file_descriptor_t* add_fd(file_descriptor_list_t* fdlist, int fd, struct file* curfile,
              const char* name) {
  if (fdlist == NULL || curfile == NULL) {
  return NULL;
  }
  file_descriptor_t* new_elem = (file_descriptor_t*)malloc(sizeof(file_descriptor_t));
  if (new_elem == NULL) {
  return NULL;
  }
  new_elem->fd = fd;
  new_elem->file_name = (const char*)malloc(sizeof(char) * (strlen(name) + 1));
  strlcpy((char*)new_elem->file_name, name, strlen(name) + 1);
  new_elem->open_file = curfile;
  list_insert(list_end(fdlist), &(new_elem->elem));
  return new_elem;
}

// Implement the logic for the close system call so that process_exit can access it
int process_file_close(int args) {
  struct thread* t = thread_current();
  lock_acquire(t->pcb->filesys_lock);
  int fd = args;
  file_descriptor_t* found = find_fd(t->pcb->file_descriptor_table, fd);
  if (found == NULL) {
  lock_release(t->pcb->filesys_lock);
  return (-1);
  } else {
  file_close(found->open_file);
  free((void*)found->file_name);
  list_remove(&(found->elem));
  free((void*)found);
  lock_release(t->pcb->filesys_lock);
  return (0);
  }
}

/* Initialize user programs in the system, ensuring that the main thread has a minimal PCB,
   so it can execute and wait for the first user process. Any additions to the PCB should be initialized here,
   if the main thread needs those members */
void userprog_init(void) {
  struct thread* t = thread_current();
  bool success;

  /* Allocate process control block
   It is very important that this is a call to calloc, not malloc,
   to ensure that when t->pcb is assigned, t->pcb->pagedir is guaranteed to be NULL (kernel's
   page directory), because a timer interrupt can happen at any time and activate our pagedir */
  t->pcb = calloc(sizeof(struct process), 1);
  success = t->pcb != NULL;

  if (success) {
  // Allocate file descriptor table pointer in the pcb
  t->pcb->file_descriptor_table = (file_descriptor_list_t*)malloc(sizeof(file_descriptor_list_t));

  // Initialize file descriptor table list
  init_fdtable(t->pcb->file_descriptor_table);

  // Set file descriptor counter
  t->pcb->fd_next = 2;

  // Allocate memory for child process list
  t->pcb->child = (metadata_list_t*)malloc(sizeof(metadata_list_t));

  // Initialize the child process list for the main thread
  list_init(t->pcb->child);

  // Initialize global file system lock and put it in the pcb
  lock_init(&filesys_lock);
  t->pcb->filesys_lock = &filesys_lock;

  // Allocate sharedata structure for the main thread
  t->shared = (metadata_t*)malloc(sizeof(metadata_t));

  // Initialize ref_cnt to 1, as the main thread will not have a parent process
  // Initialize the rest of the metadata structure elements
  t->shared->ref_cnt = 1;
  t->shared->tid = t->tid;
  lock_init(&(t->shared->tlock));
  sema_init(&(t->shared->finish), 0);
  t->shared->load_check = false;
  }
  /* If initialization is not successful, terminate the kernel */
  ASSERT(success);
}
/* Starts a new thread running a user program loaded from FILENAME.
  The new thread may be scheduled (and may even exit) before process_execute() returns.
  Returns the new process's process ID, or TID_ERROR if the thread cannot be created. */
pid_t process_execute(const char* file_name) {
  char* fn_copy;
  tid_t tid;
  struct thread* t = thread_current();

  /* Make a copy of FILE_NAME.
    Otherwise there's a race between the caller and load(). */
  fn_copy = palloc_get_page(0);
  if (fn_copy == NULL)
   return TID_ERROR;
  strlcpy(fn_copy, file_name, PGSIZE);

  // Allocate space for the child's metadata
  metadata_t* data = (metadata_t*)malloc(sizeof(metadata_t));
  // Set the copy of cmd_line into the metadata structure's element
  data->file_copy = fn_copy;
  // Initialize the semaphore for child process loading, wait until it attempts to load
  sema_init(&(data->load), 0);

  /* Create a new thread to execute FILE_NAME. */
  tid = thread_create(file_name, PRI_DEFAULT, start_process, (void*)data);
  // Call down on child's load semaphore to wait till it's attempted to load
  sema_down(&(data->load));
  if (data->load_check && tid != TID_ERROR) {
   // If loading is successful, add the child process to the parent's child process list and return tid
   list_insert(list_end(t->pcb->child), &(data->elem));
   return tid;
  } else {
   // If not successful, free the allocated metadata and free the copy of cmd_line character pointer
   free(data);
   palloc_free_page(fn_copy);
   return -1;
  }
}

/* A thread function that loads a user process and starts it running. */
static void start_process(void* newmetadata) {
  // Convert the passed void pointer to metadata structure
  metadata_t* data = (metadata_t*)newmetadata;
  // Save the cmd_line passed in metadata to file_name
  char* file_name = (char*)data->file_copy;
  struct thread* t = thread_current();

  struct intr_frame if_;
  bool success, pcb_success;

  /* Allocate process control block */
  struct process* new_pcb = malloc(sizeof(struct process));
  success = pcb_success = new_pcb != NULL;

  /* Initialize process control block */
  if (success) {
   // Ensure timer_interrupt() -> schedule() -> process_activate()
   // does not try to activate our uninitialized pagedir
   new_pcb->pagedir = NULL;
   t->pcb = new_pcb;

   // Continue initializing the PCB as normal
   t->pcb->main_thread = t;
   strlcpy(t->pcb->process_name, t->name, sizeof t->name);

   // Allocate the file_descriptor_table pointer in the PCB
   t->pcb->file_descriptor_table = (file_descriptor_list_t*)malloc(sizeof(file_descriptor_list_t));

   // Initialize the file_descriptor_table list
   init_fdtable(t->pcb->file_descriptor_table);

   // Set the file descriptor counter
   t->pcb->fd_next = 2;

   // Allocate for child list
   t->pcb->child = (metadata_list_t*)malloc(sizeof(metadata_list_t));

   // Initialize the child table
   list_init(t->pcb->child);

   // Put the shared data struct in the child
   t->shared = data;

   // Initialize the global filesystem lock and put it in the PCB
   lock_init(&filesys_lock);
   t->pcb->filesys_lock = &filesys_lock;

   // Initialize shared struct's elements
   t->shared->ref_cnt = 2;
   t->shared->tid = t->tid;
   lock_init(&(t->shared->tlock));
   sema_init(&(t->shared->finish), 0);
   t->shared->load_check = false;
  }

  /* Initialize interrupt frame and load executable. */
  if (success) {
   memset(&if_, 0, sizeof if_);
   if_.gs = if_.fs = if_.es = if_.ds = if_.ss = SEL_UDSEG;
   if_.cs = SEL_UCSEG;
   if_.eflags = FLAG_IF | FLAG_MBS;
   /* Need to save the current FPU State. */
   asm volatile("fsave %0" : "=m"(if_.fpu));
   success = load(file_name, &if_.eip, &if_.esp);
  }

  /* Handle failure if PCB allocation was successful. Must free PCB */
  if (!success && pcb_success) {
   // Avoid race conditions, set t->pcb to NULL before freeing PCB
   // If this happens, timer interrupt may try to activate pagedir, but it is now freed memory
   struct process* pcb_to_free = t->pcb;
   // Close the executable before we free the PCB
   file_close(t->pcb->executable);
   // Free malloced space for child list if load fails
   free(t->pcb->child);
   // Free malloced file descriptor table
   free(t->pcb->file_descriptor_table);
   t->pcb = NULL;
   free(pcb_to_free);
  }

  if (!success) {
   // Let the waiting parent process know the child process is done since loading was not successful
   sema_up(&(t->shared->finish));
   thread_exit();
  }

  /* Free the page allocated for file_name regardless of load success. */
  palloc_free_page(file_name);

  /* Start the user process by simulating a return from an interrupt,
    implemented in intr_exit (in threads/intr-stubs.S). Because intr_exit
    takes all its arguments on the stack in 'struct intr_frame' form,
    we just point the stack pointer to our stack frame and jump to it. */
  asm volatile("movl %0, %%esp; jmp intr_exit" : : "g"(&if_) : "memory");
  NOT_REACHED();
}
/* Waits for a child process with PID child_pid to terminate and returns its exit status.
  Returns -1 if the process was terminated by the kernel (i.e., killed due to an exception).
  Returns -1 immediately if child_pid is invalid, not a child of the calling process, or if process_wait() has already been successfully called for the given PID.

  This function will be implemented in Problem 2-2. Currently, it does nothing. */
int process_wait(pid_t child_pid) {
  struct thread* t = thread_current();
  struct list_elem* e;

  // Iterate through the child list and search for the child with the given pid
  if (!list_empty(t->pcb->child)) {
   for (e = list_begin(t->pcb->child); e != list_end(t->pcb->child); e = list_next(e)) {
    metadata_t* cur_md = list_entry(e, metadata_t, elem);
    if (cur_md->tid == child_pid) {
      // Wait until the child has finished by downing the finish semaphore
      sema_down(&(cur_md->finish));
      // Store the exit code from the child's metadata
      int exit = cur_md->exitcode;
      // Acquire lock to decrement ref_cnt to avoid race conditions
      lock_acquire(&(cur_md->tlock));
      cur_md->ref_cnt -= 1;
      int temp = cur_md->ref_cnt;
      lock_release(&(cur_md->tlock));
      // Remove the waited child from the parent's child list
      list_remove(e);
      // If ref_cnt is 0, free the metadata
      if (temp == 0) {
       free(cur_md);
      }
      // Return -1 if the exit code is -2 to handle errors properly
      return (exit == -2) ? -1 : exit;
    }
   }
  }
  return -1;
}

/* 释放当前进程的资源。 */
// Change process_exit to accept an exit code as input
void process_exit(int exit_code) {
  struct thread* cur = thread_current();
  uint32_t* pd;
  // Store the exit code in the thread's metadata
  cur->shared->exitcode = exit_code;

  /* 如果此线程没有PCB，不用担心 */
  if (cur->pcb == NULL) {
   thread_exit();
   NOT_REACHED();
  } else if (exit_code == -2) {
   // 打印退出码，如果我们由于错误而退出。设置为-2，因为只有异常应该返回
   // 退出码为-2
   printf("%s: exit(%d)\n", thread_current()->pcb->process_name, exit_code + 1);
  }

  // 在释放PCB之前关闭可执行文件
  file_close(cur->pcb->executable);

  // 遍历文件描述符列表并关闭所有仍然打开的文件描述符
  struct list_elem* e;
  while (!list_empty(cur->pcb->file_descriptor_table)) {
   e = list_begin(cur->pcb->file_descriptor_table);
   file_descriptor_t* fd_entry = list_entry(e, file_descriptor_t, elem);
   process_file_close(fd_entry->fd);
  }
  // 从堆中释放文件描述符列表
  free((void*)cur->pcb->file_descriptor_table);

  // 获取锁以减少ref_cnt以避免竞争条件并在为0时释放
  lock_acquire(&(cur->shared->tlock));
  cur->shared->ref_cnt -= 1;
  int temp = cur->shared->ref_cnt;
  lock_release(&(cur->shared->tlock));

  if (temp == 0) {
   free(cur->shared);
  }

  // 遍历所有子进程并减少其共享数据的ref_cnt
  struct list_elem* temp_next;
  if (!list_empty(cur->pcb->child)) {
   for (e = list_begin(cur->pcb->child); e != list_end(cur->pcb->child);) {
    metadata_t* cur_md = list_entry(e, metadata_t, elem);
    // 获取锁以减少ref_cnt以避免竞争条件并在为0时释放
    lock_acquire(&(cur_md->tlock));
    cur_md->ref_cnt -= 1;
    int temp = cur_md->ref_cnt;
    lock_release(&(cur_md->tlock));
    temp_next = list_next(e);
    if (temp == 0) {
      free(cur_md);
    }
    e = temp_next;
   }
  }
  // 释放子进程的子线程列表结构
  free((void*)cur->pcb->child);

  /* 销毁当前进程的页目录并切换回内核页目录。
    这里的正确顺序至关重要。我们必须在切换页目录之前设置
    cur->pcb->pagedir为NULL，以便定时器中断不能切换回
    进程页目录。我们必须在销毁进程的页目录之前激活基页
    目录，否则我们的活动页目录将是已释放（并清除）的一个。 */
  pd = cur->pcb->pagedir;
  if (pd != NULL) {
   /* 这里的正确顺序至关重要。我们必须在切换页目录之前设置
      cur->pcb->pagedir为NULL，以便定时器中断不能切换回
      进程页目录。我们必须在销毁进程的页目录之前激活基页
      目录，否则我们的活动页目录将是已释放（并清除）的一个。 */
   cur->pcb->pagedir = NULL;
   pagedir_activate(NULL);
   pagedir_destroy(pd);
  }

  /* 释放此进程的PCB并终止此线程
    避免PCB被释放之前t->pcb设置为NULL
    如果发生这种情况，那么不幸的时机不好
    定时器中断可以尝试切换到进程页
    目录。但现在它是释放的，所以没有问题。 */
  struct process* pcb_to_free = cur->pcb;
  cur->pcb = NULL;
  free(pcb_to_free);
  // 在finish信号量上进行up操作，以便等待的父进程可以继续
  sema_up(&(cur->shared->finish));

  thread_exit();
}

/* Sets up the CPU for running user code in the current
   thread. This function is called on every context switch. */
void process_activate(void) {
  struct thread* t = thread_current();

  /* Activate thread's page tables. */
  if (t->pcb != NULL && t->pcb->pagedir != NULL)
    pagedir_activate(t->pcb->pagedir);
  else
    pagedir_activate(NULL);

  /* Set thread's kernel stack for use in processing interrupts.
     This does nothing if this is not a user process. */
  tss_update();
}

/* We load ELF binaries.  The following definitions are taken
   from the ELF specification, [ELF1], more-or-less verbatim.  */

/* ELF types.  See [ELF1] 1-2. */
typedef uint32_t Elf32_Word, Elf32_Addr, Elf32_Off;
typedef uint16_t Elf32_Half;

/* For use with ELF types in printf(). */
#define PE32Wx PRIx32 /* Print Elf32_Word in hexadecimal. */
#define PE32Ax PRIx32 /* Print Elf32_Addr in hexadecimal. */
#define PE32Ox PRIx32 /* Print Elf32_Off in hexadecimal. */
#define PE32Hx PRIx16 /* Print Elf32_Half in hexadecimal. */

/* Executable header.  See [ELF1] 1-4 to 1-8.
   This appears at the very beginning of an ELF binary. */
struct Elf32_Ehdr {
  unsigned char e_ident[16];
  Elf32_Half e_type;
  Elf32_Half e_machine;
  Elf32_Word e_version;
  Elf32_Addr e_entry;
  Elf32_Off e_phoff;
  Elf32_Off e_shoff;
  Elf32_Word e_flags;
  Elf32_Half e_ehsize;
  Elf32_Half e_phentsize;
  Elf32_Half e_phnum;
  Elf32_Half e_shentsize;
  Elf32_Half e_shnum;
  Elf32_Half e_shstrndx;
};

/* Program header.  See [ELF1] 2-2 to 2-4.
   There are e_phnum of these, starting at file offset e_phoff
   (see [ELF1] 1-6). */
struct Elf32_Phdr {
  Elf32_Word p_type;
  Elf32_Off p_offset;
  Elf32_Addr p_vaddr;
  Elf32_Addr p_paddr;
  Elf32_Word p_filesz;
  Elf32_Word p_memsz;
  Elf32_Word p_flags;
  Elf32_Word p_align;
};

/* Values for p_type.  See [ELF1] 2-3. */
#define PT_NULL 0           /* Ignore. */
#define PT_LOAD 1           /* Loadable segment. */
#define PT_DYNAMIC 2        /* Dynamic linking info. */
#define PT_INTERP 3         /* Name of dynamic loader. */
#define PT_NOTE 4           /* Auxiliary info. */
#define PT_SHLIB 5          /* Reserved. */
#define PT_PHDR 6           /* Program header table. */
#define PT_STACK 0x6474e551 /* Stack segment. */

/* Flags for p_flags.  See [ELF3] 2-3 and 2-4. */
#define PF_X 1 /* Executable. */
#define PF_W 2 /* Writable. */
#define PF_R 4 /* Readable. */

static bool setup_stack(void** esp);
static bool validate_segment(const struct Elf32_Phdr*, struct file*);
static bool load_segment(struct file* file, off_t ofs, uint8_t* upage, uint32_t read_bytes,
                         uint32_t zero_bytes, bool writable);

// 声明全局变量
extern const char* test_name;
bool load(const char* file_name, void (**eip)(void), void** esp) {
  struct thread* t = thread_current();
  struct Elf32_Ehdr ehdr;
  struct file* file = NULL;
  off_t file_ofs;
  bool success = false;
  int i;

  //___START____: Code By Shaamer For Argument Passing PART 1/2

  //Make a copy of the entire command line
  char* file_copy = malloc(sizeof(char) * (strlen(file_name) + 1));
  strlcpy(file_copy, file_name, strlen(file_name) + 1);

  //Calculate the number of args
  int numspaces = 0;

  //Boolean protection against double+ spaces
  bool last = false;

  //Loop to count the number of spces = args -1
  for (unsigned i = 0; i < strlen(file_name); i++) {
    if (file_name[i] == ' ') {
      if (!last) {
        numspaces += 1;
        last = true;
      }
    } else {
      last = false;
    }
  }

  //Number of args
  int argc = numspaces + 1;

  //Creating the argv array
  char* argv[argc + 1];

  //Set the last element of argv to Null
  argv[argc] = NULL;

  //Counter to access argv array
  int counter = 0;

  // How to use Strtok_r on https://www.geeksforgeeks.org/strtok-strtok_r-functions-c-examples/
  char* saveptr = NULL;
  for (char* token_elem = strtok_r(file_copy, " ", &saveptr); token_elem != NULL;
       token_elem = strtok_r(NULL, " ", &saveptr)) {

    // Parse file, store in argv
    int len = strlen(token_elem);
    argv[counter] = (char*)malloc(sizeof(char) * (len + 1));
    strlcpy(argv[counter], token_elem, len + 1);
    counter++;
  }

  // test_name = argv[0];
  // printf(test_name);
  // if (test_name == NULL) {
  //   test_name = argv[0];
  //   printf("load:  %s\n", test_name);
  // }
  // else {
  //   // printf('test_name is not null');
  //   // printf('argv[0] is %s \n', argv[0]);
  //   // printf(t->test_name);
  //   printf("load:  %s\n", test_name);
  // }


  //Check if there are no arguments
  if (argc == 0) {
    //we passed in something empty
    success = false;
    printf("%s/n", "Didn't pass in anything");
    return success;
  }

  //Set the process name to be the name of the test/executable
  strlcpy(t->pcb->process_name, argv[0], strlen(argv[0]) + 1);

  /* PUSHING TO STACK IMPLEMENTED BELOW IN PART 2.*/

  //___END____: Code By Shaamer For Argument Passing PART 1/2

  /* Allocate and activate page directory. */
  t->pcb->pagedir = pagedir_create();
  if (t->pcb->pagedir == NULL)
    goto done;
  process_activate();

  /* Open executable file. */
  //SHAAMER CHANGED THE INPUT TO FILESYS_OPEN BELOW from file_name to argv[0]
  file = filesys_open(argv[0]);
  if (file == NULL) {
    printf("load: %s: open failed\n", file_name);
    goto done;
    //putting the executable into the pcb so we can close it in process exit
  } else {
    t->pcb->executable = file;
    file_deny_write(file);
  }

  /* Read and verify executable header. */
  if (file_read(file, &ehdr, sizeof ehdr) != sizeof ehdr ||
      memcmp(ehdr.e_ident, "\177ELF\1\1\1", 7) || ehdr.e_type != 2 || ehdr.e_machine != 3 ||
      ehdr.e_version != 1 || ehdr.e_phentsize != sizeof(struct Elf32_Phdr) || ehdr.e_phnum > 1024) {
    printf("load: %s: error loading executable\n", file_name);
    goto done;
  }

  /* Read program headers. */
  file_ofs = ehdr.e_phoff;
  for (i = 0; i < ehdr.e_phnum; i++) {
    struct Elf32_Phdr phdr;

    if (file_ofs < 0 || file_ofs > file_length(file))
      goto done;
    file_seek(file, file_ofs);

    if (file_read(file, &phdr, sizeof phdr) != sizeof phdr)
      goto done;
    file_ofs += sizeof phdr;
    switch (phdr.p_type) {
      case PT_NULL:
      case PT_NOTE:
      case PT_PHDR:
      case PT_STACK:
      default:
        /* Ignore this segment. */
        break;
      case PT_DYNAMIC:
      case PT_INTERP:
      case PT_SHLIB:
        goto done;
      case PT_LOAD:
        if (validate_segment(&phdr, file)) {
          bool writable = (phdr.p_flags & PF_W) != 0;
          uint32_t file_page = phdr.p_offset & ~PGMASK;
          uint32_t mem_page = phdr.p_vaddr & ~PGMASK;
          uint32_t page_offset = phdr.p_vaddr & PGMASK;
          uint32_t read_bytes, zero_bytes;
          if (phdr.p_filesz > 0) {
            /* Normal segment.
                     Read initial part from disk and zero the rest. */
            read_bytes = page_offset + phdr.p_filesz;
            zero_bytes = (ROUND_UP(page_offset + phdr.p_memsz, PGSIZE) - read_bytes);
          } else {
            /* Entirely zero.
                     Don't read anything from disk. */
            read_bytes = 0;
            zero_bytes = ROUND_UP(page_offset + phdr.p_memsz, PGSIZE);
          }
          if (!load_segment(file, file_page, (void*)mem_page, read_bytes, zero_bytes, writable))
            goto done;
        } else
          goto done;
        break;
    }
  }

  /* Set up stack. */
  if (!setup_stack(esp))
    goto done;

  /* Start address. */
  *eip = (void (*)(void))ehdr.e_entry;

  //___START____: Code By Shaamer For Argument Passing PART 2/2

  //Push the actual arguments onto the stack in reverse order
  for (int k = argc - 1; k >= 0; k--) {
    *esp -= strlen(argv[k]) + 1;
    memcpy(*esp, argv[k], strlen(argv[k]) + 1);
    argv[k] = *esp;
  }
  /*START STACK ALIGN*/
  // arg pointers + nullpointer + **argv + argc
  int numpointers = 3 + argc;
  int amount_to_decrement = ((unsigned)*esp - numpointers * 4) % 16;
  *esp -= amount_to_decrement;
  /*END STACK ALIGN*/

  /*push addresses of arguments in reverse order*/
  for (int k = argc; k >= 0; k--) {
    *esp -= 4;
    *(uint32_t*)*esp = (int)(uint32_t*)argv[k];
  }

  /*push **argv */
  *esp -= 4;
  *(uint32_t*)*esp = (int)(*esp + 4);

  /*push argc */
  *esp -= 4;
  *(uint32_t*)*esp = argc;

  /*push fake return address */
  *esp -= 4;
  *(uint32_t*)*esp = 0;

  //___END____: Code By Shaamer For Argument Passing PART 2/2

  success = true;

done:
  /* We arrive here whether the load is successful or not. */
  //Commenting this out here so we can close the executable in process exit and prevent writing to the executable
  //during the entire process
  //file_close(file);

  //Free resources if the load fails
  if (!success) {
    free(file_copy);
    for (int i = 0; i < counter; i++) {
      free(argv[i]);
    }
  }

  //store loads success status in the threads metadata
  t->shared->load_check = success;
  //up load semaphore for process_execute to continue executing
  sema_up(&(t->shared->load));
  return success;
}

/* load() helpers. */

static bool install_page(void* upage, void* kpage, bool writable);

/* Checks whether PHDR describes a valid, loadable segment in
   FILE and returns true if so, false otherwise. */
static bool validate_segment(const struct Elf32_Phdr* phdr, struct file* file) {
  /* p_offset and p_vaddr must have the same page offset. */
  if ((phdr->p_offset & PGMASK) != (phdr->p_vaddr & PGMASK))
    return false;

  if (phdr->p_offset > (Elf32_Off)file_length(file))
    return false;

  if (phdr->p_memsz < phdr->p_filesz)
    return false;

  if (phdr->p_memsz == 0)
    return false;

  if (!is_user_vaddr((void*)phdr->p_vaddr))
    return false;
  if (!is_user_vaddr((void*)(phdr->p_vaddr + phdr->p_memsz)))
    return false;

  if (phdr->p_vaddr + phdr->p_memsz < phdr->p_vaddr)
    return false;

  if (phdr->p_vaddr < PGSIZE)
    return false;

  /* It's okay. */
  return true;
}

/* 从文件的偏移量OFS处加载一个段到地址UPAGE。
   总共，初始化READ_BYTES + ZERO_BYTES字节的虚拟内存，具体如下：

        - 必须从文件的偏移量OFS开始，从文件中读取UPAGE处的READ_BYTES字节。

        - 必须将UPAGE + READ_BYTES处的ZERO_BYTES字节清零。

   如果WRITABLE为true，则由用户进程初始化的页面必须是可写的，否则为只读。

   如果成功返回true，如果发生内存分配错误或磁盘读取错误则返回false。 */
static bool load_segment(struct file* file, off_t ofs, uint8_t* upage, uint32_t read_bytes,
                         uint32_t zero_bytes, bool writable) {
  ASSERT((read_bytes + zero_bytes) % PGSIZE == 0);
  ASSERT(pg_ofs(upage) == 0);
  ASSERT(ofs % PGSIZE == 0);

  file_seek(file, ofs);
  while (read_bytes > 0 || zero_bytes > 0) {
    /* 从文件的偏移量OFS处加载一个段到地址UPAGE。
   总共，初始化READ_BYTES + ZERO_BYTES字节的虚拟内存，具体如下：

        - 必须从文件的偏移量OFS开始，从文件中读取UPAGE处的READ_BYTES字节。

        - 必须将UPAGE + READ_BYTES处的ZERO_BYTES字节清零。

   如果WRITABLE为true，则由用户进程初始化的页面必须是可写的，否则为只读。

   如果成功返回true，如果发生内存分配错误或磁盘读取错误则返回false。 */
    size_t page_read_bytes = read_bytes < PGSIZE ? read_bytes : PGSIZE;
    size_t page_zero_bytes = PGSIZE - page_read_bytes;

    /* Get a page of memory. */
    uint8_t* kpage = palloc_get_page(PAL_USER);
    if (kpage == NULL)
      return false;

    /* Load this page. */
    if (file_read(file, kpage, page_read_bytes) != (int)page_read_bytes) {
      palloc_free_page(kpage);
      return false;
    }
    memset(kpage + page_read_bytes, 0, page_zero_bytes);

    /* Add the page to the process's address space. */
    if (!install_page(upage, kpage, writable)) {
      palloc_free_page(kpage);
      return false;
    }

    /* Advance. */
    read_bytes -= page_read_bytes;
    zero_bytes -= page_zero_bytes;
    upage += PGSIZE;
  }
  return true;
}

/* Create a minimal stack by mapping a zeroed page at the top of
   user virtual memory. */
static bool setup_stack(void** esp) {
  uint8_t* kpage;
  bool success = false;

  kpage = palloc_get_page(PAL_USER | PAL_ZERO);
  if (kpage != NULL) {
    success = install_page(((uint8_t*)PHYS_BASE) - PGSIZE, kpage, true);
    if (success)
      *esp = PHYS_BASE;
    else
      palloc_free_page(kpage);
  }
  return success;
}

/* 向页表中添加一个从用户虚拟地址UPAGE到内核虚拟地址KPAGE的映射。
   如果WRITABLE为true，用户进程可以修改页面；
   否则为只读。
   UPAGE不能已经被映射。
   KPAGE应该是使用palloc_get_page()从用户池中获得的页面。
   如果成功返回true，如果UPAGE已经映射或内存分配失败则返回false。 */
static bool install_page(void* upage, void* kpage, bool writable) {
  struct thread* t = thread_current();

  /* 验证在那个虚拟地址上已经没有页面，
     然后在那里映射我们的页面。 */
  return (pagedir_get_page(t->pcb->pagedir, upage) == NULL &&
          pagedir_set_page(t->pcb->pagedir, upage, kpage, writable));
}

/* Returns true if t is the main thread of the process p */
bool is_main_thread(struct thread* t, struct process* p) { return p->main_thread == t; }

/* Gets the PID of a process */
pid_t get_pid(struct process* p) { return (pid_t)p->main_thread->tid; }

/* 为线程创建一个新的堆栈并设置其参数。
   存储线程的入口点到*EIP和其初始堆栈指针到*ESP。
   如果不成功，处理所有清理操作。如果成功返回true，否则返回false。

   此函数将在Project 2: 多线程中实现。目前什么也不做。您可能需要更改函数签名。 */
bool setup_thread(void (**eip)(void) UNUSED, void** esp UNUSED) { return false; }

/* 使用新的用户堆栈在顶部运行SF的新线程，该线程以TF和ARG作为参数。
   此新线程可能在pthread_execute ()返回之前被调度（甚至可能退出）。
   如果线程无法正确创建，则返回新线程的TID或TID_ERROR。

   此函数将在Project 2: 多线程中实现，并且应该类似于process_execute ()。
   目前什么也不做。 */
tid_t pthread_execute(stub_fun sf UNUSED, pthread_fun tf UNUSED, void* arg UNUSED) { return -1; }

/* 创建一个新的用户线程并启动它运行的线程函数。
   负责将自身添加到PCB中的线程列表中。

   此函数将在Project 2: 多线程中实现，并且应该类似于start_process ()。
   目前什么也不做。 */
static void start_pthread(void* exec_ UNUSED) {}

/* 等待具有TID的线程死亡，如果该线程在同一进程中生成并且尚未被等待，则等待。
   成功时返回TID，并在失败时立即返回TID_ERROR。

   此函数将在Project 2: 多线程中实现。目前什么也不做。 */
tid_t pthread_join(tid_t tid UNUSED) { return -1; }

/* 释放当前线程的资源。大多数资源将在thread_exit()上释放，所以我们只需释放线程的用户堆栈。
   唤醒等待此线程的任何线程。

   主线程不应使用此函数。参见pthread_exit_main()下面。

   此函数将在Project 2: 多线程中实现。目前什么也不做。 */
void pthread_exit(void) {}
/* 仅在主线程明确调用pthread_exit时使用。
   主线程应等待进程中的所有线程正常终止，然后才能自行退出。
   当主线程自己退出时，必须终止进程以及在pthread_exit中执行的所有必要任务。

   此函数将在Project 2: 多线程中实现。目前什么也不做。 */
void pthread_exit_main(void) {}
