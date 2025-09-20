#ifndef THREADS_SYNCH_H
#define THREADS_SYNCH_H

#include <list.h>
#include <stdbool.h>

/* A counting semaphore. */
struct semaphore {
  unsigned value;      /* Current value. */
  struct list waiters;/* List of waiting threads. */
};

void sema_init(struct semaphore*, unsigned value);/*Initialize semaphore*/
void sema_down(struct semaphore*);/*Get semaphore (block call)*/
bool sema_try_down(struct semaphore*);/*Attempting to obtain semaphores (non blocking calls)*/
void sema_up(struct semaphore*);/*Release signal quantity*/
void sema_self_test(void);/*Execute a self-test function to test the functionality of the semaphore*/

/* Lock. */
struct lock {
  struct thread* holder;      /* Thread holding lock (for debugging). */
  struct semaphore semaphore; /* Binary semaphore controlling access. */
  struct list_elem elem;      /* Priority Donation List Elements. */
  int max_priority;
};


void lock_init(struct lock*); /*Initialize lock*/
void lock_release(struct lock*);/*Release lock*/
bool lock_try_acquire(struct lock*);/*Attempt to acquire lock (non blocking call)*/
void lock_acquire(struct lock*);/*Obtain lock (block call)*/
bool lock_held_by_current_thread(const struct lock*);/*Check if the current thread holds the lock*/

/* Condition variable. */
struct condition {
  struct list waiters;  /* List of waiting threads. */
};


void cond_init(struct condition*);/*Initialize conditional variables*/
void cond_signal(struct condition*, struct lock*);/*Thread that sends signal notifications to wait for condition variables*/
void cond_broadcast(struct condition*, struct lock*);/*Broadcast signal notifies all threads waiting for condition variables*/
void cond_wait(struct condition*, struct lock*);/*Wait for conditional variable (on given lock)*/
/*Compare two list elements and a priority donation function to determine which thread should continue executing*/
bool cond_sema_cmp_priority (const struct list_elem *a, const struct list_elem *b, void *aux);

/* Readers-writers lock. */
#define RW_READER 1 
#define RW_WRITER 0

struct rw_lock {
  struct lock lock; 
  struct condition read; 
  struct condition write;
  int AR, WR, AW, WW;
};


void rw_lock_init(struct rw_lock*);
void rw_lock_release(struct rw_lock*, bool reader);
void rw_lock_acquire(struct rw_lock*, bool reader);



/* Optimization barrier.

   The compiler will not reorder operations across an
   optimization barrier.  See "Optimization Barriers" in the
   reference guide for more information.*/
#define barrier() asm volatile("" : : : "memory")

#endif /* threads/synch.h */
