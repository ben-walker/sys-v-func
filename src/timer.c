/**
 * Ben Walker
 * CIS*3110
 * 
 * Timing library; uses a static struct timeval to track the
 * elapsed time between startTimer() and stopTimer() calls
 */

#include "timer.h"
#include <sys/time.h>
#include <stdlib.h>

static struct timeval start; // tracks the start time of the timer
static const int CONV = 1000000; // microsecond conversion

/**
 * startTimer()
 * Store current "time of day" in the static struct
 */
void startTimer() {
   gettimeofday(&start, NULL);
}

/**
 * stopTimer()
 * Return difference between current moment and start moment,
 * in microseconds
 */
int stopTimer() {
   struct timeval end;
   gettimeofday(&end, NULL);
   return (end.tv_sec - start.tv_sec) * CONV + (end.tv_usec - start.tv_usec);
}
