#include "args.h"
#include "numbers.h"
#include "validation.h"
#include "timer.h"
#include "cFiling.h"
#include "unixFiling.h"
#include <stdio.h>
#include <stdlib.h>

const char *FILE_OPT = "-f";
const char *BYTE_OPT = "-b";
const char *TYPE_OPT = "-t";

void incorrectUsage(const char *programName) {
   fprintf(stderr, "Usage: %s %s filename %s bytes %s callType\n", programName, FILE_OPT, BYTE_OPT, TYPE_OPT);
}

void describeUsage(const char *file, int bytes, int unixCall) {
   const char *callStatement = unixCall == 1
      ? "Using Unix I/O system calls to read"
      : "Using C functions to read";
   const char *byteTemplate = bytes == 1
      ? "%d byte from %s"
      : "%d bytes from %s";
   char byteStatement[256];
   snprintf(byteStatement, sizeof(byteStatement), byteTemplate, bytes, file);
   const char *readStatement = unixCall == 1
      ? "with read."
      : bytes == 1
         ? "with fgetc."
         : "with fread.";
   printf("%s %s %s\n", callStatement, byteStatement, readStatement);
}

int main(int argc, const char *argv[]) {
   int bytes = 0, unixCall = 0;
   const char *file = getArgForOpt(argc, argv, FILE_OPT);

   if (
      file == NULL ||
      convertToNum(getArgForOpt(argc, argv, BYTE_OPT), &bytes) == EXIT_FAILURE ||
      convertToNum(getArgForOpt(argc, argv, TYPE_OPT), &unixCall) == EXIT_FAILURE
   ) {
      incorrectUsage(argv[0]);
      exit(EXIT_FAILURE);
   }

   if (argsInvalid(file, bytes, unixCall))
      exit(EXIT_FAILURE);
   describeUsage(file, bytes, unixCall);

   startTimer();
   if (unixCall == 1)
      unixReadFile(file, bytes);
   else
      cReadFile(file, bytes);
   int duration = stopTimer();
   printf("Elapsed time:   %d\n", duration);
   return 0;
}
