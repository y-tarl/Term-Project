#include "filesys/file.h"
#include "filesys/filesys.h"
#include "threads/vaddr.h"
#include "userprog/pagedir.h"
#include "threads/synch.h"
#include <stdlib.h>
#include <string.h>
#include "userprog/syscall.h"
#include <stdio.h>
#include <syscall-nr.h>
#include "threads/interrupt.h"
#include "threads/thread.h"
#include "userprog/process.h"


int input_getc(void);
void free(void* __ptr);
int shutdown_power_off(void);
int sys_sum_to_e(int n);
static void syscall_handler(struct intr_frame*);

void syscall_init(void) { intr_register_int(0x30, 3, INTR_ON, syscall_handler, "syscall"); }
// 检查传递到内核的指针是否有效的函数
bool is_valid_ptr(char* ptr) {
  struct thread* t = thread_current();

  // 检查指针是否为空
  if (ptr == NULL) {
    return false;
  }
  // 检查整个内存地址是否在用户空间中
  if (!is_user_vaddr(ptr) || !is_user_vaddr(ptr + 3)) {
    return false;
  }

  // 检查整个内存地址是否在映射的内存中
  if (pagedir_get_page(t->pcb->pagedir, ptr) == NULL ||
      pagedir_get_page(t->pcb->pagedir, (ptr + 3)) == NULL) {
    return false;
  }
  return true;
}

// Function to check if integers passed into the kernel are valid
bool is_valid_int(uint32_t* ptr) {
  return is_valid_ptr(((char*)ptr)) && is_valid_ptr(((char*)ptr) + 3);
}
static void syscall_handler(struct intr_frame* f UNUSED) {
  // This is the exit code we set for exiting due to an exception
  // Check if we have a valid stack pointer
  if (!is_valid_ptr((char*)f->esp)) {
    process_exit(-2);
  }

  uint32_t* args = ((uint32_t*)f->esp);

  /*
   * 如果取消注释以下的打印语句，那么每当一个进程进入系统调用时，它将打印出系统调用号。
   * 在调试时可能会有用，但会导致测试失败，因此不应包含在最终提交中。
   */
  /*
   * The following print statement, if uncommented, will print out the syscall
   * number whenever a process enters a system call. You might find it useful
   * when debugging. It will cause tests to fail, however, so you should not
   * include it in your final submission.
   */

  /* printf("System call number: %d\n", args[0]); */
  // Check if arg[0] is in a valid memory region
  if (!is_valid_int(&args[0])) {
    // Exit as an exception/error
    process_exit(-2);
  }




  if (args[0] == SYS_EXIT) {
    // Ensure integer arguments are valid
    if (!is_valid_int(&args[1])) {
      // Exit as an exception/error
      process_exit(-2);
    }
    // Set the return value to the exit code
    f->eax = args[1];
    printf("%s: exit(%d)\n", thread_current()->pcb->process_name, args[1]);
    process_exit(args[1]);
  } else if (args[0] == SYS_EXEC) {
    // Check if the pointer is valid
    if (!is_valid_ptr((char*)args[1])) {
      // Exit as an exception/error
      process_exit(-2);
    }
    // Store cmd_line in a variable to pass to process_execute
    const char* cmnd_line = (const char*)args[1];
    // Store the pid returned by process_execute in eax and return
    f->eax = process_execute(cmnd_line);
    return;
  } else if (args[0] == SYS_WAIT) {
    if (!is_valid_int(&args[1])) {
      // Exit as an exception/error
      process_exit(-2);
    }
    // Store the exit code returned by process_wait in eax and return
    f->eax = process_wait((pid_t)args[1]);
    return;
  } else if (args[0] == SYS_WRITE) {
    // Get the current thread so we can access pcb
    struct thread* t = thread_current();

    // Acquire the global file system lock
    lock_acquire(t->pcb->filesys_lock);

    // Check if the pointer is valid
    if (!is_valid_ptr((char*)args[2]) || !is_valid_int(&args[1]) || !is_valid_int(&args[3])) {
      // Release the file system lock and exit
      lock_release(t->pcb->filesys_lock);

      // Exit as an exception/error
      process_exit(-2);
    }

    // Get the file descriptor passed into the system call
    int fd = args[1];

    // Get the buffer pointer to write to
    void* buffer = (void*)args[2];

    // Get the number of bytes to write
    // Possible error: not sure if we need to check if this is zero
    unsigned size = args[3];

    // Check if the file descriptor is valid. Cannot write to stdin
    if (fd <= 0) {
      // Set the return value
      f->eax = -1;
      // Release the file system lock
      lock_release(t->pcb->filesys_lock);
      return;
    }

    // Check if writing to stdout
    if (fd == 1) {

      if (size <= 200) {
        // Write the entire buffer in one call to putbuf
        putbuf(buffer, size);
      } else {
        // Split the buffer into smaller chunks and write each chunk until the entire buffer is written
        unsigned offset = 0;
        while (offset < size) {
          int chunk_size = size - offset;
          if (chunk_size > 200) {
            chunk_size = 200;
          }
          putbuf(buffer + offset, chunk_size);
          offset += chunk_size;
        }
      }

      // Set the return value
      f->eax = size;

      // Release the file system lock
      lock_release(t->pcb->filesys_lock);
      return;

      // Otherwise we are writing to a file descriptor
    } else {

      // Get the entry in the file descriptor table and check if it exists
      file_descriptor_t* table_entry = find_fd(t->pcb->file_descriptor_table, fd);
      if (table_entry == NULL) {
        // Set the return value
        f->eax = -1;
        // Release the file system lock
        lock_release(t->pcb->filesys_lock);
        return;
      }

      // Get the open file from the table entry
      struct file* open_file = table_entry->open_file;

      // Variable to hold the number of bytes written
      int bytes_written = 0;
      if (size <= 200) {
        // Write the entire buffer in one call to file_write
        bytes_written = file_write(open_file, buffer, size);
      } else {
        // Split the buffer into smaller chunks and iterate writing until complete
        unsigned offset = 0;
        while (offset < size) {
          int chunk_size = size - offset;
          if (chunk_size > 200) {
            chunk_size = 200;
          }
          bytes_written += file_write(open_file, buffer + offset, chunk_size);
          offset += chunk_size;
        }
      }

      // Set the return value
      f->eax = bytes_written;

      // Release the file system lock
      lock_release(t->pcb->filesys_lock);

      return;
    }
  }
  // Implement practice system call
  else if (args[0] == SYS_PRACTICE) {
    // Increment argument 1 and store in eax
    f->eax = args[1] + 1;
    return;
  }
  // Implement Halt system call
  else if (args[0] == SYS_HALT) {
    // Call shutdown_power_off()
    shutdown_power_off();
  }
  
  
  
  if (args[0] == SYS_CREATE) {
    struct thread* t = thread_current();
    lock_acquire(t->pcb->filesys_lock);

    if (!is_valid_ptr((char*)args[1]) || !is_valid_int(&args[2])) {
      lock_release(t->pcb->filesys_lock);
      process_exit(-2);
    }

    const char* file = (const char*)args[1];

    if (strlen(file) > 14) {
      f->eax = false;
      lock_release(t->pcb->filesys_lock);
      return;
    }

    unsigned size = args[2];
    bool success = filesys_create(file, size);
    f->eax = success;
    lock_release(t->pcb->filesys_lock);
    return;

  } else if (args[0] == SYS_REMOVE) {
    struct thread* t = thread_current();
    lock_acquire(t->pcb->filesys_lock);

    void* ptr = (void*)args[1];
    if (!is_valid_ptr((char*)ptr)) {
      lock_release(t->pcb->filesys_lock);
      process_exit(-2);
    }
    const char* file = (const char*)ptr;
    bool success = filesys_remove(file);
    f->eax = success;
    lock_release(t->pcb->filesys_lock);
    return;

  } else if (args[0] == SYS_OPEN) {
    struct thread* t = thread_current();
    lock_acquire(t->pcb->filesys_lock);

    void* ptr = (void*)args[1];
    if (!is_valid_ptr((char*)ptr)) {
      lock_release(t->pcb->filesys_lock);
      process_exit(-2);
    }
    const char* file = (const char*)ptr;
    file_descriptor_t* exists = find_filename(t->pcb->file_descriptor_table, file);
    int newfd;

    if (exists == NULL) {
      newfd = t->pcb->fd_next++;
      struct file* open_file = filesys_open(file);
      if (open_file == NULL) {
        f->eax = -1;
        lock_release(t->pcb->filesys_lock);
        return;
      }
      add_fd(t->pcb->file_descriptor_table, newfd, open_file, file);
    } else {
      newfd = t->pcb->fd_next++;
      struct file* open_file = file_reopen(exists->open_file);
      if (open_file == NULL) {
        f->eax = -1;
        lock_release(t->pcb->filesys_lock);
        return;
      }
      add_fd(t->pcb->file_descriptor_table, newfd, open_file, file);
    }

    f->eax = newfd;
    lock_release(t->pcb->filesys_lock);
    return;

  } else if (args[0] == SYS_SEEK) {
    struct thread* t = thread_current();
    lock_acquire(t->pcb->filesys_lock);

    if (!is_valid_int(&args[1]) || !is_valid_int(&args[2])) {
      lock_release(t->pcb->filesys_lock);
      process_exit(-2);
    }

    int fd = args[1];
    file_descriptor_t* found = find_fd(t->pcb->file_descriptor_table, fd);

    if (found == NULL) {
      lock_release(t->pcb->filesys_lock);
      return;
    } else {
      unsigned size = args[2];
      file_seek(found->open_file, size);
      lock_release(t->pcb->filesys_lock);
      return;
    }
  } else if (args[0] == SYS_TELL) {
    struct thread* t = thread_current();
    lock_acquire(t->pcb->filesys_lock);

    if (!is_valid_int(&args[1])) {
      lock_release(t->pcb->filesys_lock);
      process_exit(-2);
    }

    int fd = args[1];
    file_descriptor_t* found = find_fd(t->pcb->file_descriptor_table, fd);

    if (found == NULL) {
      f->eax = -1;
      lock_release(t->pcb->filesys_lock);
      return;
    } else {
      off_t tell = file_tell(found->open_file);
      f->eax = tell;
      lock_release(t->pcb->filesys_lock);
      return;
    }
  } else if (args[0] == SYS_CLOSE) {
    if (!is_valid_int(&args[1])) {
      process_exit(-2);
    }
    f->eax = process_file_close((int)args[1]);
    return;
  } else if (args[0] == SYS_FILESIZE) {
    struct thread* t = thread_current();
    lock_acquire(t->pcb->filesys_lock);

    if (!is_valid_int(&args[1])) {
      lock_release(t->pcb->filesys_lock);
      process_exit(-2);
    }

    int fd = args[1];
    file_descriptor_t* found = find_fd(t->pcb->file_descriptor_table, fd);

    if (found == NULL) {
      f->eax = -1;
      lock_release(t->pcb->filesys_lock);
      return;
    } else {
      off_t len = file_length(found->open_file);
      f->eax = len;
      lock_release(t->pcb->filesys_lock);
      return;
    }
  } else if (args[0] == SYS_READ) {
    struct thread* t = thread_current();
    lock_acquire(t->pcb->filesys_lock);

    if (!is_valid_ptr((char*)args[2]) || !is_valid_int(&args[1]) || !is_valid_int(&args[3])) {
      lock_release(t->pcb->filesys_lock);
      process_exit(-2);
    }

    int fd = args[1];
    unsigned size = args[3];

    if (fd == 1 || fd < 0) {
      f->eax = -1;
      lock_release(t->pcb->filesys_lock);
      return;
    }

    if (fd == 0) {
      char* buffer = (char*)args[2];
      for (unsigned i = 0; i < size; i++) {
        buffer[i] = input_getc();
      }
      f->eax = size;
      lock_release(t->pcb->filesys_lock);
      return;
    } else {
      void* buffer = (void*)args[2];
      file_descriptor_t* table_entry = find_fd(t->pcb->file_descriptor_table, fd);
      if (table_entry == NULL) {
        f->eax = -1;
        lock_release(t->pcb->filesys_lock);
        return;
      }

      struct file* open_file = table_entry->open_file;
      int read = file_read(open_file, buffer, size);
      f->eax = read;
      lock_release(t->pcb->filesys_lock);
      return;
    }
  } else if (args[0] == SYS_COMPUTE_E) {
    int n = args[1];
    if (n < 0) {
      process_exit(-2);
    } else {
      f->eax = sys_sum_to_e(n);
      return;
    }
  }
}
