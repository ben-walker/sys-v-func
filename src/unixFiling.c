/**
 * Ben Walker
 * CIS*3110
 * 
 * Implementation of Unix file reading with open/read/close
 */

#include "unixFiling.h"
#include "timer.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * unixReadFile()
 * Return the amount of time it takes to read a file using
 * Unix system calls
 */
int unixReadFile(const char *file, int bytes) {
   int fd = open(file, O_RDONLY);
   if (fd == -1) {
      perror("open");
      exit(EXIT_FAILURE);
   }

   startTimer(); // only time the reading
   char buff[bytes];
   while (read(fd, buff, bytes) != 0);
   int duration = stopTimer();

   if (close(fd) == -1) {
      perror("close");
      exit(EXIT_FAILURE);
   }
   return duration;
}
