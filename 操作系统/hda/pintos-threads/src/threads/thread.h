#ifndef THREADS_THREAD_H
#define THREADS_THREAD_H

#include <debug.h>
#include <list.h>
#include <stdint.h>
#include "threads/synch.h"
#include "threads/fixed-point.h"



/* States in a thread's life cycle. */
enum thread_status {
  THREAD_RUNNING, /* Running thread. */
  THREAD_READY,   /* Not running but ready to run. */
  THREAD_BLOCKED, /* Waiting for an event to trigger. */
  THREAD_DYING    /* About to be destroyed. */
};
/* Thread identifier type.
   You can redefine this to whatever type you like. */
typedef int tid_t;
#define TID_ERROR ((tid_t) - 1) /* Error value for tid_t. */

/* Thread priorities. */
#define PRI_MIN 0      /* Lowest priority. */
#define PRI_DEFAULT 31 /* Default priority. */
#define PRI_MAX 63     /* Highest priority. */
/* A kernel thread or user process.

   Each thread structure is stored in its own 4 kB page.  The
   thread structure itself sits at the very bottom of the page
   (at offset 0).  The rest of the page is reserved for the
   thread's kernel stack, which grows downward from the top of
   the page (at offset 4 kB).  Here's an illustration:

        4 kB +---------------------------------+
             |          kernel stack           |
             |                |                |
             |                |                |
             |                V                |
             |         grows downward          |
             |                                 |
             |                                 |
             |                                 |
             |                                 |
             |                                 |
             |                                 |
             |                                 |
             |                                 |
             +---------------------------------+
             |              magic              |
             |                :                |
             |                :                |
             |               name              |
             |              status             |
        0 kB +---------------------------------+

   The upshot of this is twofold:

      1. First, `struct thread' must not be allowed to grow too
         big.  If it does, then there will not be enough room for
         the kernel stack.  Our base `struct thread' is only a
         few bytes in size.  It probably should stay well under 1
         kB.

      2. Second, kernel stacks must not be allowed to grow too
         large.  If a stack overflows, it will corrupt the thread
         state.  Thus, kernel functions should not allocate large
         structures or arrays as non-static local variables.  Use
         dynamic allocation with malloc() or palloc_get_page()
         instead.

   The first symptom of either of these problems will probably be
   an assertion failure in thread_current(), which checks that
   the `magic' member of the running thread's `struct thread' is
   set to THREAD_MAGIC.  Stack overflow will normally change this
   value, triggering the assertion. */

/* The `elem' member has a dual purpose.  It can be an element in
   the run queue (thread.c), or it can be an element in a
   semaphore wait list (synch.c).  It can be used these two ways
   only because they are mutually exclusive: only a thread in the
   ready state is on the run queue, whereas only a thread in the
   blocked state is on a semaphore wait list. */
struct thread {
  /* Owned by thread.c. */
  tid_t tid;                 /* Thread identifier. */
  enum thread_status status; /* Thread state. */
  char name[16];             /* Name (for debugging purposes). */
  uint8_t* stack;            /* Saved stack pointer. */
  int priority;              /* Priority. */
  struct list_elem allelem;  /* List element for all threads list. */
  int64_t sleep_ticks;       // 记录阻塞的时间
  int ticks;                 // 线程的时间片或相关的计时信息
  int original_priority;     // 基本优先级
  struct list held_locks;    // 当前线程持有的锁列表
  struct lock* lock_waiting; // 线程正在等待的锁

  int nice;           // 线程的nice值，影响调度行为
  fixed_t recent_cpu; // 最近的CPU使用时间

  /* Shared between thread.c and synch.c. */
  struct list_elem elem; /* List element. */

#ifdef USERPROG
  /* Owned by process.c. */
  struct process* pcb; /* Process control block if this thread is a userprog */
#endif

  /* Owned by thread.c. */
  unsigned magic; /* Detects stack overflow. */
};

/* Types of scheduler that the user can request the kernel
 * use to schedule threads at runtime. */
enum sched_policy {
  SCHED_FIFO,  // First-in, first-out scheduler
  SCHED_PRIO,  // Strict-priority scheduler with round-robin tiebreaking
  SCHED_FAIR,  // Implementation-defined fair scheduler
  SCHED_MLFQS, // Multi-level Feedback Queue Scheduler
};

#define SCHED_DEFAULT SCHED_FIFO

/* Determines which scheduling policy the kernel should use.
 * Controller by the kernel command-line options
 *  "-sched-default", "-sched-fair", "-sched-mlfqs", "-sched-fifo"
 * Is equal to SCHED_FIFO by default. */
extern enum sched_policy active_sched_policy;
// 标记是否使用MLFQS调度程序
extern bool thread_mlfqs;
// 线程初始化函数
void thread_init(void);
// 时钟中断时调用的线程处理函数
void thread_tick(void);
// 打印线程统计信息的函数
void thread_print_stats(void);
// 启动线程的函数
void thread_start(void);

// 定义一个线程函数类型，该类型接受一个void指针作为参数
typedef void thread_func(void* aux);
// 创建一个新线程并返回线程ID
tid_t thread_create(const char* name, int priority, thread_func*, void*);

// 阻塞当前线程
void thread_block(void);
// 解除线程阻塞
void thread_unblock(struct thread*);

// 获取当前线程的指针
struct thread* thread_current(void);
// 获取当前线程的ID
tid_t thread_tid(void);
// 获取当前线程的名称
const char* thread_name(void);

// 退出当前线程，不返回任何值
void thread_exit(void) NO_RETURN;
// 放弃当前线程的CPU使用权，让其他线程运行
void thread_yield(void);

// 定义一个操作，该操作对线程执行某些操作并传递辅助数据AUX
typedef void thread_action_func(struct thread* t, void* aux);
// 对所有线程执行操作，AUX作为每个线程的参数
void thread_foreach(thread_action_func*, void*);
// 获取当前线程的nice值（影响调度优先级）
int thread_get_nice(void);
// 获取当前线程的优先级
int thread_get_priority(void);
// 设置当前线程的优先级
void thread_set_priority(int);
// 设置当前线程的nice值（影响调度优先级）
void thread_set_nice(int);
// 获取平均负载值，可能是特定线程或全局的
int thread_get_load_avg(void);
// 获取最新的CPU使用时间，可能是特定线程或全局的
int thread_get_recent_cpu(void);
// 持有锁可能是为了等待或防止其他线程获取锁
void thread_hold_the_lock(struct lock* lock);
// 释放之前持有的锁，允许其他线程获取
void thread_remove_lock(struct lock* lock);
// 更新线程优先级或相关调度信息（由具体函数决定）
void thread_priority_renewal(struct thread* t);
// 检查阻塞的线程是否满足某些条件（由具体函数决定）
void unblock_timeup_thread(struct thread* t, void* aux UNUSED);
// 比较两个线程或锁元素的优先级（由具体函数决定）
bool cmp_priority_thread(const struct list_elem* a, const struct list_elem* b, void* aux UNUSED);
// 提高线程优先级可能是为了实现某种调度策略（如多级反馈队列）
void thread_priority_donation(struct thread* t);
// 根据多级反馈队列调度程序（MLFQS）策略更新线程优先级
void update_pri_mlfqs(struct thread* t);
// 比较两个锁元素的优先级（由具体函数决定）
bool cmp_priority_lock(const struct list_elem* a, const struct list_elem* b, void* aux UNUSED);
// 增加最近的CPU使用时间可能是实现多级反馈队列调度程序（MLFQS）策略的一部分
void increate_recent_CPU_mlfqs(void);
// 更新负载平均值和最近的CPU使用时间可能是实现多级反馈队列调度程序（MLFQS）策略的一部分
void update_LA_and_RC_mlfqs(void);
// 更新线程的ticks值可能是为了实现某种公平调度策略
void thread_fair_update_ticks(void);
#endif /* threads/thread.h */
