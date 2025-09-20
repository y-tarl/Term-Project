#ifndef USERPROG_PROCESS_H
#define USERPROG_PROCESS_H
#include "threads/thread.h"
#include <stdint.h>
#include <list.h>

// Maximum stack allocation is 8MB
// These definitions will be used in Project 2: Multithreading
#define MAX_STACK_PAGES (1 << 11)
#define MAX_THREADS 127

/* PIDs and TIDs are the same type. PID should be
  the TID of the process's main thread */
typedef tid_t pid_t;

/* Thread function (Project 2: Multithreading) */
typedef void (*pthread_fun)(void*);
typedef void (*stub_fun)(pthread_fun, void*);

// Define metadata_list_t as a list that acts as a Pintos list for shared data of child processes
typedef struct list metadata_list_t;

// Create file descriptor table structure
typedef struct file_descriptor {
  int fd;                 // File descriptor
  const char* file_name;  // File name
  struct file* open_file; // Opened file
  struct list_elem elem;  // Pintos list element
} file_descriptor_t;

// Create a new definition for the list
typedef struct list file_descriptor_list_t;

/* Process control block for a given process. Since each process can have multiple threads,
  we need a PCB that is independent of TCB. All TCBs in the process will have a pointer to the PCB,
  and the PCB will have a pointer to the main thread of the process, which is `special`. */
struct process {
  /* Owned by process.c. */
  uint32_t* pagedir;          /* Page directory. */
  char process_name[16];      /* Name of the main thread */
  struct thread* main_thread; /* Pointer to the main thread */

  /* Add a struct list child as a Pintos list
  for shared data of all child processes in its PCB */
  metadata_list_t* child;

  // File descriptor table structure
  file_descriptor_list_t* file_descriptor_table;

  // File descriptor counter
  int fd_next;

  // Global lock for file system system calls
  struct lock* filesys_lock;

  // Pointer to the executable file to close it when the process exits
  struct file* executable;
};

void userprog_init(void);

pid_t process_execute(const char* file_name);
int process_wait(pid_t);
void process_exit(int exit_code);
void process_activate(void);

bool is_main_thread(struct thread*, struct process*);
pid_t get_pid(struct process*);

tid_t pthread_execute(stub_fun, pthread_fun, void*);
tid_t pthread_join(tid_t);
void pthread_exit(void);
void pthread_exit_main(void);

/* Initialize file descriptor table list. */
void init_fdtable(file_descriptor_list_t* fdlist);

/* Add a file descriptor to the file descriptor list. */
file_descriptor_t* add_fd(file_descriptor_list_t* fdlist, int fd, struct file* curfile,
                  const char* name);

/* Find a file descriptor in the file descriptor list. */
file_descriptor_t* find_fd(file_descriptor_list_t* fdlist, int fd);

// Find file name in the file descriptor table
file_descriptor_t* find_filename(file_descriptor_list_t* fdlist, const char* name);

// Close system call
int process_file_close(int args);

#endif /* userprog/process.h */