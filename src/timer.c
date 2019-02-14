#include "timer.h"
#include <sys/time.h>

static struct timeval start;
static const int CONV = 1000000;

void startTimer() {
   gettimeofday(&start, NULL);
}

int stopTimer() {
   struct timeval end;
   gettimeofday(&end, NULL);
   return (end.tv_sec - start.tv_sec) * CONV + (end.tv_usec - start.tv_usec);
}
