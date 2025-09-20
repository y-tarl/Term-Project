#include "threads/thread.h"
#include <debug.h>
#include <stddef.h>
#include <random.h>
#include <stdio.h>
#include <string.h>
#include "threads/flags.h"
#include "threads/interrupt.h"
#include "threads/intr-stubs.h"
#include "threads/palloc.h"
#include "threads/switch.h"
#include "threads/synch.h"
#include "threads/vaddr.h"
#ifdef USERPROG
#include "userprog/process.h"
#endif

/* Random value for struct thread's `magic' member.
   Used to detect stack overflow.  See the big comment at the top
   of thread.h for details. */
#define THREAD_MAGIC 0xcd6abf4b
fixed_t load_avg;
extern bool hierarchical_scheduling;
/* List of processes in THREAD_READY state, that is, processes
   that are ready to run but not actually running. */
static struct list fifo_ready_list;

/* List of all processes.  Processes are added to this list
   when they are first scheduled and removed when they exit. */
static struct list all_list;

/* Idle thread. */
static struct thread* idle_thread;

/* Initial thread, the thread running init.c:main(). */
static struct thread* initial_thread;

/* Lock used by allocate_tid(). */
static struct lock tid_lock;

/* Stack frame for kernel_thread(). */
struct kernel_thread_frame {
  void* eip;             /* Return address. */
  thread_func* function; /* Function to call. */
  void* aux;             /* Auxiliary data for function. */
};

/* Scheduling. */
#define TIME_SLICE 4 /* # of timer ticks to give each thread. */
bool thread_mlfqs;
static unsigned thread_ticks; /* # of timer ticks since last yield. */
static void init_thread(struct thread*, const char* name, int priority);
static void schedule(void);
static void thread_enqueue(struct thread* t);
static tid_t allocate_tid(void);
static bool is_thread(struct thread*) UNUSED;
static void* alloc_frame(struct thread*, size_t size);
void thread_switch_tail(struct thread* prev);
static void kernel_thread(thread_func*, void* aux);
static void idle(void* aux UNUSED);
static struct thread* running_thread(void);
static struct thread* next_thread_to_run(void);
static struct thread* thread_schedule_fifo(void);
static struct thread* thread_schedule_prio(void);
static struct thread* thread_schedule_fair(void);
static struct thread* thread_schedule_mlfqs(void);
bool schedule_started;
static struct thread* thread_schedule_reserved(void);

/* Statistics. */
static long long user_ticks;   /* # of timer ticks in user programs. */
static long long idle_ticks;   /* # of timer ticks spent idle. */
static long long kernel_ticks; /* # of timer ticks in kernel threads. */

/* Initializes the threading system by transforming the code
   that's currently running into a thread.  This can't work in
   general and it is possible in this case only because loader.S
   was careful to put the bottom of the stack at a page boundary.

   Also initializes the run queue and the tid lock.

   After calling this function, be sure to initialize the page
   allocator before trying to create any threads with
   thread_create().

   It is not safe to call thread_current() until this function
   finishes. */
void thread_init(void) {
  ASSERT(intr_get_level() == INTR_OFF);

  lock_init(&tid_lock);
  list_init(&fifo_ready_list);
  list_init(&all_list);

  /* Set up a thread structure for the running thread. */
  initial_thread = running_thread();
  init_thread(initial_thread, "main", PRI_DEFAULT);
  initial_thread->status = THREAD_RUNNING;
  initial_thread->tid = allocate_tid();
}

/* Called by the timer interrupt handler at each timer tick.
   Thus, this function runs in an external interrupt context. */
void thread_tick(void) {
  struct thread* t = thread_current();

  /* Update statistics. */
  if (t == idle_thread)
    idle_ticks++;
#ifdef USERPROG
  else if (t->pcb != NULL)
    user_ticks++;
#endif
  else
    kernel_ticks++;

  /* Enforce preemption. */
  if (++thread_ticks >= TIME_SLICE)
    intr_yield_on_return();
}

/* Determines which scheduler the kernel should use.
   Controlled by the kernel command-line options
    "-sched=fifo", "-sched=prio",
    "-sched=fair". "-sched=mlfqs"
   Is equal to SCHED_FIFO by default. */
enum sched_policy active_sched_policy;

/* Selects a thread to run from the ready list according to
   some scheduling policy, and returns a pointer to it. */
typedef struct thread* scheduler_func(void);

/* Jump table for dynamically dispatching the current scheduling
   policy in use by the kernel. */
scheduler_func* scheduler_jump_table[8] = {thread_schedule_fifo,     thread_schedule_prio,
                                           thread_schedule_fair,     thread_schedule_mlfqs,
                                           thread_schedule_reserved, thread_schedule_reserved,
                                           thread_schedule_reserved, thread_schedule_reserved};

/* Prints thread statistics. */
void thread_print_stats(void) {
  printf("Thread: %lld idle ticks, %lld kernel ticks, %lld user ticks\n", idle_ticks, kernel_ticks,
         user_ticks);
}

/* Creates a new kernel thread named NAME with the given initial
   PRIORITY, which executes FUNCTION passing AUX as the argument,
   and adds it to the ready queue.  Returns the thread identifier
   for the new thread, or TID_ERROR if creation fails.

   If thread_start() has been called, then the new thread may be
   scheduled before thread_create() returns.  It could even exit
   before thread_create() returns.  Contrariwise, the original
   thread may run for any amount of time before the new thread is
   scheduled.  Use a semaphore or some other form of
   synchronization if you need to ensure ordering.

   The code provided sets the new thread's `priority' member to
   PRIORITY, but no actual priority scheduling is implemented.
   Priority scheduling is the goal of Problem 1-3. */
tid_t thread_create(const char* name, int priority, thread_func* function, void* aux) {
  struct thread* t;
  struct kernel_thread_frame* kf;
  struct switch_entry_frame* ef;
  struct switch_threads_frame* sf;
  tid_t tid;

  ASSERT(function != NULL);

  /* Allocate thread. */
  t = palloc_get_page(PAL_ZERO);
  if (t == NULL)
    return TID_ERROR;

  /* Initialize thread. */
  init_thread(t, name, priority);
  tid = t->tid = allocate_tid();
  t->sleep_ticks = 0;

  /* Stack frame for kernel_thread(). */
  kf = alloc_frame(t, sizeof *kf);
  kf->eip = NULL;
  kf->function = function;
  kf->aux = aux;

  /* Stack frame for switch_entry(). */
  ef = alloc_frame(t, sizeof *ef);
  ef->eip = (void (*)(void))kernel_thread;

  /* Stack frame for switch_threads(). */
  sf = alloc_frame(t, sizeof *sf);
  sf->eip = switch_entry;
  sf->ebp = 0;

  /* Add to ready-to-run queue. */
  thread_unblock(t);

  if (thread_current()->priority < priority) {
    // If priority of the current thread is lower than the priority of the new one.
    thread_yield();
  }
  return tid;
}

/*Start preemptive thread scheduling by enabling interrupts. Idle threads were also created*/
void thread_start(void) {
  /* Create the idle thread. */
  struct semaphore idle_started;
  load_avg = CAL_FIXED_POINT_CONST(0);
  schedule_started = true;
  sema_init(&idle_started, 0);
  thread_create("idle", PRI_MIN, idle, &idle_started);

  /* Start preemptive thread scheduling. */
  intr_enable();

  /* Wait for the idle thread to initialize idle_thread. */
  sema_down(&idle_started);
}

/*Place the thread on a suitable ready structure according to the current proactive scheduling strategy.
 This function must be called with an interrupt closed*/
static void thread_enqueue(struct thread* t) {
  ASSERT(intr_get_level() == INTR_OFF);
  ASSERT(is_thread(t));

  if (active_sched_policy == SCHED_FIFO)
    list_push_back(&fifo_ready_list, &t->elem);
  else
    PANIC("Unimplemented scheduling policy value: %d", active_sched_policy);
}

/*Put the current thread into sleep mode. It will not be scheduled
 to wait again until it is thread_ Unblock() wakes up.
 This function must be called with an interrupt closed*/
void thread_block(void) {
  ASSERT(!intr_context());
  ASSERT(intr_get_level() == INTR_OFF);

  thread_current()->status = THREAD_BLOCKED;
  schedule();
}

/* Transitions a blocked thread T to the ready-to-run state.
   This is an error if T is not blocked.  (Use thread_yield() to
   make the running thread ready.)

   This function does not preempt the running thread.  This can
   be important: if the caller had disabled interrupts itself,
   it may expect that it can atomically unblock a thread and
   update other data. */
void thread_unblock(struct thread* t) {
  enum intr_level old_level;

  ASSERT(is_thread(t));

  old_level = intr_disable();
  ASSERT(t->status == THREAD_BLOCKED);
  // Here, the code is changed.
  list_insert_ordered(&fifo_ready_list, &t->elem, (list_less_func*)&cmp_priority_thread, NULL);
  //thread_enqueue(t);
  t->status = THREAD_READY;
  intr_set_level(old_level);
}

/*Check the blocked threads and unblock them if the blocking time has passed*/
void unblock_timeup_thread(struct thread* t, void* aux UNUSED) {
  if (t->status == THREAD_BLOCKED && t->sleep_ticks > 0) {
    t->sleep_ticks--;
    if (t->sleep_ticks == 0) {
      thread_unblock(t);
    }
  }
}

/* Returns the running thread's tid. */
tid_t thread_tid(void) { return thread_current()->tid; }

/*Returns the name of the running thread*/
const char* thread_name(void) { return thread_current()->name; }

/* Returns the running thread.
   This is running_thread() plus a couple of sanity checks.
   See the big comment at the top of thread.h for details. */
struct thread* thread_current(void) {
  struct thread* t = running_thread();

  /* Make sure T is really a thread.
     If either of these assertions fire, then your thread may
     have overflowed its stack.  Each thread has less than 4 kB
     of stack, so a few big automatic arrays or moderate
     recursion can cause stack overflow. */
  ASSERT(is_thread(t));
  ASSERT(t->status == THREAD_RUNNING);

  return t;
}

/* Deschedules the current thread and destroys it.  Never
   returns to the caller. */
void thread_exit(void) {
  ASSERT(!intr_context());

  /* Remove thread from all threads list, set our status to dying,
     and schedule another process.  That process will destroy us
     when it calls thread_switch_tail(). */
  intr_disable();
  list_remove(&thread_current()->allelem);
  thread_current()->status = THREAD_DYING;
  schedule();
  NOT_REACHED();
}

/* Yields the CPU.  The current thread is not put to sleep and
   may be scheduled again immediately at the scheduler's whim. */
void thread_yield(void) {
  if (!schedule_started)
    return;
  struct thread* cur = thread_current();
  enum intr_level old_level;

  ASSERT(!intr_context());

  old_level = intr_disable();
  if (cur != idle_thread)
    list_insert_ordered(&fifo_ready_list, &cur->elem, (list_less_func*)&cmp_priority_thread, NULL);
  cur->status = THREAD_READY;
  schedule();
  intr_set_level(old_level);
}

/* Invoke function 'func' on all threads, passing along 'aux'.
   This function must be called with interrupts off. */
void thread_foreach(thread_action_func* func, void* aux) {
  struct list_elem* e;

  ASSERT(intr_get_level() == INTR_OFF);

  for (e = list_begin(&all_list); e != list_end(&all_list); e = list_next(e)) {
    struct thread* t = list_entry(e, struct thread, allelem);
    func(t, aux);
  }
}

/* Returns the current thread's nice value. */
int thread_get_nice(void) {
  /* Not yet implemented. */
  return thread_current()->nice;
}

/* Sets the current thread's nice value to NICE. */
void thread_set_nice(int nice UNUSED) { /* Not yet implemented. */
  thread_current()->nice = nice;
  update_pri_mlfqs(thread_current());
  thread_yield();
}

/* Return priority of the current thread. */
int thread_get_priority(void) { return thread_current()->priority; }

/* Sets the current thread's priority to NEW_PRIORITY. */
void thread_set_priority(int new_priority) {
  if (active_sched_policy == SCHED_FAIR)
    return;

  enum intr_level old_level = intr_disable();

  struct thread* current_thread = thread_current();
  int old_priority = current_thread->priority;
  current_thread->original_priority = new_priority;

  if (list_empty(&current_thread->held_locks) || new_priority > old_priority) {
    current_thread->priority = new_priority;
    thread_yield();
  }

  intr_set_level(old_level);
}

/* Return 100 times the average system load*/
int thread_get_load_avg(void) {
  /* Not yet implemented. */
  return CAL_FIXED_POINT_ROUND(CAL_FIXED_POINT_MULT_MIX(load_avg, 100));
}

/*Return the current thread recent_ 100 times the CPU value*/
int thread_get_recent_cpu(void) {
  /* Not yet implemented. */
  return CAL_FIXED_POINT_ROUND(CAL_FIXED_POINT_MULT_MIX(thread_current()->recent_cpu, 100));
}

/* If T seems to point to a valid thread, return true*/
static bool is_thread(struct thread* t) { return t != NULL && t->magic == THREAD_MAGIC; }

/* Idle thread.  Executes when no other thread is ready to run.

   The idle thread is initially put on the ready list by
   thread_start().  It will be scheduled once initially, at which
   point it initializes idle_thread, "up"s the semaphore passed
   to it to enable thread_start() to continue, and immediately
   blocks.  After that, the idle thread never appears in the
   ready list.  It is returned by next_thread_to_run() as a
   special case when the ready list is empty. */
static void idle(void* idle_started_ UNUSED) {
  struct semaphore* idle_started = idle_started_;
  idle_thread = thread_current();
  sema_up(idle_started);

  for (;;) {
    /* Let someone else run. */
    intr_disable();
    thread_block();

    /* Re-enable interrupts and wait for the next one.

         The `sti' instruction disables interrupts until the
         completion of the next instruction, so these two
         instructions are executed atomically.  This atomicity is
         important; otherwise, an interrupt could be handled
         between re-enabling interrupts and waiting for the next
         one to occur, wasting as much as one clock tick worth of
         time.

         See [IA32-v2a] "HLT", [IA32-v2b] "STI", and [IA32-v3a]
         7.11.1 "HLT Instruction". */
    asm volatile("sti; hlt" : : : "memory");
  }
}

/* Function used as the basis for a kernel thread. */
static void kernel_thread(thread_func* function, void* aux) {
  ASSERT(function != NULL);

  intr_enable(); /* The scheduler runs with interrupts off. */
  function(aux); /* Execute the thread function. */
  thread_exit(); /* If function() returns, kill the thread. */
}

/* Returns the running thread. */
struct thread* running_thread(void) {
  uint32_t* esp;

  /* Copy the CPU's stack pointer into `esp', and then round that
     down to the start of a page.  Because `struct thread' is
     always at the beginning of a page and the stack pointer is
     somewhere in the middle, this locates the curent thread. */
  asm("mov %%esp, %0" : "=g"(esp));
  return pg_round_down(esp);
}

/* Does basic initialization of T as a blocked thread named
   NAME. */
static void init_thread(struct thread* t, const char* name, int priority) {
  enum intr_level old_level;

  ASSERT(t != NULL);
  ASSERT(PRI_MIN <= priority && priority <= PRI_MAX);
  ASSERT(name != NULL);

  memset(t, 0, sizeof *t);
  t->status = THREAD_BLOCKED;
  strlcpy(t->name, name, sizeof t->name);
  t->stack = (uint8_t*)t + PGSIZE;
  t->priority = priority;
#ifdef USERPROG
  t->pcb = NULL;
#endif
  t->magic = THREAD_MAGIC;
  t->original_priority = priority;
  list_init(&t->held_locks);
  t->lock_waiting = NULL;
  t->ticks = 0;

  if (hierarchical_scheduling) {
    t->nice = 0;
  } else {
    if (priority == 56)
      t->nice = 0;
    else if (priority == 48)
      t->nice = 1;
    else if (priority == 40)
      t->nice = 2;
    else if (priority == 32)
      t->nice = 3;
    else if (priority == 24)
      t->nice = 4;
    else if (priority == 16)
      t->nice = 5;
    else if (priority == 8)
      t->nice = 6;
    else if (priority == 0)
      t->nice = 7;
  }
  t->recent_cpu = CAL_FIXED_POINT_CONST(0);

  old_level = intr_disable();
  list_insert_ordered(&all_list, &t->allelem, (list_less_func*)&cmp_priority_thread, NULL);
  intr_set_level(old_level);
}

/* Allocates a SIZE-byte frame at the top of thread T's stack and
   returns a pointer to the frame's base. */
static void* alloc_frame(struct thread* t, size_t size) {
  /* Stack data is always allocated in word-size units. */
  ASSERT(is_thread(t));
  ASSERT(size % sizeof(uint32_t) == 0);

  t->stack -= size;
  return t->stack;
}

/* Strict priority scheduler */
static struct thread* thread_schedule_prio(void) {
  if (!list_empty(&fifo_ready_list))
    return list_entry(list_pop_front(&fifo_ready_list), struct thread, elem);
  else
    return idle_thread;
}

/* First-in first-out scheduler */
static struct thread* thread_schedule_fifo(void) {
  if (!list_empty(&fifo_ready_list))
    return list_entry(list_pop_front(&fifo_ready_list), struct thread, elem);
  else
    return idle_thread;
}

/* Not an actual scheduling policy — placeholder for empty
 * slots in the scheduler jump table. */
static struct thread* thread_schedule_reserved(void) {
  if (!list_empty(&fifo_ready_list))
    return list_entry(list_pop_front(&fifo_ready_list), struct thread, elem);
  else
    return idle_thread;
}

/* Fair priority scheduler */
static struct thread* thread_schedule_fair(void) {
  if (!list_empty(&fifo_ready_list))
    return list_entry(list_pop_front(&fifo_ready_list), struct thread, elem);
  else
    return idle_thread;
}

/* Multi-level feedback queue scheduler */
static struct thread* thread_schedule_mlfqs(void) {
  if (!list_empty(&fifo_ready_list))
    return list_entry(list_pop_front(&fifo_ready_list), struct thread, elem);
  else
    return idle_thread;
}

/* Chooses and returns the next thread to be scheduled.  Should
   return a thread from the run queue, unless the run queue is
   empty.  (If the running thread can continue running, then it
   will be in the run queue.)  If the run queue is empty, return
   idle_thread. */
static struct thread* next_thread_to_run(void) {
  if (!list_empty(&fifo_ready_list))
    return list_entry(list_pop_front(&fifo_ready_list), struct thread, elem);
  else
    return idle_thread;
}

/* Completes a thread switch by activating the new thread's page
   tables, and, if the previous thread is dying, destroying it.

   At this function's invocation, we just switched from thread
   PREV, the new thread is already running, and interrupts are
   still disabled.  This function is normally invoked by
   thread_switch() as its final action before returning, but
   the first time a thread is scheduled it is called by
   switch_entry() (see switch.S).

   It's not safe to call printf() until the thread switch is
   complete.  In practice that means that printf()s should be
   added at the end of the function.

   After this function and its caller returns, the thread switch
   is complete. */
void thread_switch_tail(struct thread* prev) {
  struct thread* cur = running_thread();

  ASSERT(intr_get_level() == INTR_OFF);

  /* Mark us as running. */
  cur->status = THREAD_RUNNING;

  /* Start new time slice. */
  thread_ticks = 0;

#ifdef USERPROG
  /* Activate the new address space. */
  process_activate();
#endif

  /* If the thread we switched from is dying, destroy its struct
     thread.  This must happen late so that thread_exit() doesn't
     pull out the rug under itself.  (We don't free
     initial_thread because its memory was not obtained via
     palloc().) */
  if (prev != NULL && prev->status == THREAD_DYING && prev != initial_thread) {
    ASSERT(prev != cur);
    palloc_free_page(prev);
  }
}

/* Returns a tid to use for a new thread. */
static tid_t allocate_tid(void) {
  static tid_t next_tid = 1;
  tid_t tid;

  lock_acquire(&tid_lock);
  tid = next_tid++;
  lock_release(&tid_lock);

  return tid;
}

/* Schedules a new thread.  At entry, interrupts must be off and
   the running process's state must have been changed from
   running to some other state.  This function finds another
   thread to run and switches to it.

   It's not safe to call printf() until thread_switch_tail()
   has completed. */
static void schedule(void) {
  struct thread* cur = running_thread();
  struct thread* next = next_thread_to_run();
  struct thread* prev = NULL;
  //msg("M%d--d%d--d%d",cur->priority,cur->nice,cur->original_priority);
  ASSERT(intr_get_level() == INTR_OFF);
  ASSERT(cur->status != THREAD_RUNNING);
  ASSERT(is_thread(next));

  if (cur != next)
    prev = switch_threads(cur, next);
  thread_switch_tail(prev);
}

/*A function used to compare the priority of two threads, used for sorting operations in a list*/
bool cmp_priority_thread(const struct list_elem* a, const struct list_elem* b, void* aux UNUSED) {
  return list_entry(a, struct thread, elem)->priority >
         list_entry(b, struct thread, elem)->priority;
}

/*Adjust the priority of the thread and reinsert it into the ready queue*/
void thread_priority_donation(struct thread* t) {
  enum intr_level old_level = intr_disable();
  thread_priority_renewal(t);

  // If the thread state is THREAD_READY, otherwise, its statu is THREAD_RUNNING
  if (t->status == THREAD_READY) {
    list_remove(&t->elem);
    list_insert_ordered(&fifo_ready_list, &t->elem, cmp_priority_thread, NULL);
  }

  intr_set_level(old_level);
}

/*A thread holds (acquires) a lock*/
void thread_hold_the_lock(struct lock* lock) {
  enum intr_level old_level = intr_disable();

  list_insert_ordered(&thread_current()->held_locks, &lock->elem, cmp_priority_lock, NULL);
  // If the priority of the lock is higher than the current thread's priority
  if (lock->max_priority > thread_current()->priority) {
    thread_current()->priority = lock->max_priority;
    thread_yield();
  }
  // Restore the previously saved interrupt level
  intr_set_level(old_level);
}

// Update system average load and recent CPU usage
void update_LA_and_RC_mlfqs() {
  ASSERT(active_sched_policy == SCHED_FAIR);
  ASSERT(intr_context());

  // Get the number of ready threads
  size_t ready_cnt = list_size(&fifo_ready_list);
  if (thread_current() != idle_thread)
    ++ready_cnt;
  // Update system average load
  load_avg =
      CAL_FIXED_POINT_ADD(CAL_FIXED_POINT_DIV_MIX(CAL_FIXED_POINT_MULT_MIX(load_avg, 59), 60),
                          CAL_FIXED_POINT_DIV_MIX(CAL_FIXED_POINT_CONST(ready_cnt), 60));

  struct thread* t;
  struct list_elem* e;
  // Traverse all thread lists
  for (e = list_begin(&all_list); e != list_end(&all_list); e = list_next(e)) {
    t = list_entry(e, struct thread, allelem);
    if (t != idle_thread) {
      t->recent_cpu = CAL_FIXED_POINT_ADD_MIX(
          CAL_FIXED_POINT_MULT(
              CAL_FIXED_POINT_DIV(FIXED_MULT_2_F(load_avg, 1),
                                  CAL_FIXED_POINT_ADD_MIX(FIXED_MULT_2_F(load_avg, 1), 1)),
              t->recent_cpu),
          0);

      update_pri_mlfqs(t);
    }
  }
}

// Remove the specified lock from the lock list
void thread_remove_lock(struct lock* lock) {
  enum intr_level old_level = intr_disable();

  list_remove(&lock->elem);
  thread_priority_renewal(thread_current());

  intr_set_level(old_level);
}

/* Update the priority of threads and adjust
  it based on the priority of the locks they hold*/
void thread_priority_renewal(struct thread* t) {
  enum intr_level old_level = intr_disable();
  int reasonable_priority = t->original_priority; // Initialize maximum priority to basic priority
  int max_lock_priority;                          // Priority used to store locks

  if (!list_empty(&t->held_locks)) {
    //Sort the lock list based on the maximum priority of the lock
    list_sort(&t->held_locks, cmp_priority_lock, NULL);
    max_lock_priority = list_entry(list_front(&t->held_locks), struct lock, elem)->max_priority;
    if (max_lock_priority > reasonable_priority)
      reasonable_priority = max_lock_priority;
  }

  //Set the priority of the thread to the maximum
  //priority value and store it in the thread structure
  t->priority = reasonable_priority;
  intr_set_level(old_level);
}

/*A function that compares the priority of two locks, 
  used for ` list_ The sort ` function performs sorting operations.
  Return value: Returns true when the priority of the first lock is greater than that of the second lock*/
bool cmp_priority_lock(const struct list_elem* a, const struct list_elem* b, void* aux UNUSED) {
  return list_entry(a, struct lock, elem)->max_priority >
         list_entry(b, struct lock, elem)->max_priority;
}

//Increase the recent CPU usage counter value of the thread for subsequent calculation of thread priority.
//This function must be called in an interrupt context.
void increate_recent_CPU_mlfqs() {
  ASSERT(active_sched_policy == SCHED_FAIR);
  ASSERT(intr_context());

  struct thread* cur = thread_current();
  if (cur == idle_thread)
    return;
  cur->recent_cpu = CAL_FIXED_POINT_ADD_MIX(cur->recent_cpu, 1);
}

// Update thread priority
void update_pri_mlfqs(struct thread* t) {
  ASSERT(active_sched_policy == SCHED_FAIR);

  if (t == idle_thread)
    return;
  /*Whether to use hierarchycal scheduling or not*/
  if (hierarchical_scheduling) {
    t->priority = CAL_FIXED_POINT_INT_PART(
        CAL_FIXED_POINT_SUB_MIX(CAL_FIXED_POINT_SUB(CAL_FIXED_POINT_CONST(PRI_MAX),
                                                    (CAL_FIXED_POINT_DIV_MIX(t->recent_cpu, 4))),
                                t->nice));
  } else {
    t->priority = CAL_FIXED_POINT_INT_PART(
        CAL_FIXED_POINT_SUB_MIX(CAL_FIXED_POINT_SUB(CAL_FIXED_POINT_CONST(PRI_MAX),
                                                    CAL_FIXED_POINT_DIV_MIX(t->recent_cpu, 4)),
                                0));
  }

  /*clamp the priority.*/
  if (t->priority < PRI_MIN)
    t->priority = PRI_MIN;
  else if (t->priority > PRI_MAX)
    t->priority = PRI_MAX;
}

// Update the TICKS of the thread and handle the corresponding scheduling behavior
void thread_fair_update_ticks(void) {
  struct thread* current_thread = thread_current();
  //If the current thread is an idle thread, return
  if (current_thread == idle_thread)
    return;

  current_thread->ticks = current_thread->ticks + 1;

  if (current_thread->ticks >= current_thread->priority) {
    current_thread->ticks = 0;
    if (!intr_context())
      thread_yield();
    else
      intr_yield_on_return();
  }
}

/* Offset of `stack' member within `struct thread'.
   Used by switch.S, which can't figure it out on its own. */
uint32_t thread_stack_ofs = offsetof(struct thread, stack);
