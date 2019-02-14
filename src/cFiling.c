/**
 * Ben Walker
 * CIS*3110
 * 
 * Implementation of C file reading with fopen/fgetc/fread/fclose
 */

#include "cFiling.h"
#include "timer.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * cReadFile()
 * Return the amount of time it takes to read a file using
 * C functions
 */
int cReadFile(const char *file, int bytes) {
   FILE *fp = fopen(file, "r");
   if (fp == NULL) {
      perror("fopen");
      exit(EXIT_FAILURE);
   }

   startTimer(); // only time the reading
   if (bytes == 1)
      while (fgetc(fp) != EOF); // use fgetc to read byte-by-byte
   else {
      char buff[bytes];
      while (fread(buff, 1, bytes, fp) == bytes); // use fread to read in chunks
   }
   int duration = stopTimer();

   fclose(fp);
   return duration;
}
