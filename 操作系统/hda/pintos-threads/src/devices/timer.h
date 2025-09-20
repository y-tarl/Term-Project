#ifndef DEVICES_TIMER_H
#define DEVICES_TIMER_H

#include <round.h>
#include <stdint.h>

/*Timer interrupts per second*/
#define TIMER_FREQ 1000

void timer_init(void);/*Initialize timer*/
void timer_calibrate(void);/*Calibrate timer*/

int64_t timer_elapsed(int64_t);/*Calculate the number of ticks passed by the timer*/
int64_t timer_ticks(void);/*Get the current timer ticks*/

/* Sleep and yield the CPU to other threads. */
void timer_sleep(int64_t ticks);
/* Real time sleep. */
void timer_nsleep(int64_t nanoseconds); // ns
void timer_usleep(int64_t microseconds);// us
void timer_msleep(int64_t milliseconds);// ms

/* Busy waits. */
void timer_ndelay(int64_t nanoseconds);
void timer_udelay(int64_t microseconds);
void timer_mdelay(int64_t milliseconds);

/* Print statistics for timers*/
void timer_print_stats(void);

#endif /* devices/timer.h */
