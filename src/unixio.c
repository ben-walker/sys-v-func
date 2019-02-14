#include "args.h"
#include "numbers.h"
#include <stdio.h>
#include <stdlib.h>

const char *FILE_OPT = "-f";
const char *BYTE_OPT = "-b";
const char *TYPE_OPT = "-t";

void incorrectUsage(const char *programName) {
   fprintf(stderr, "Usage: %s %s filename %s bytes %s callType\n", programName, FILE_OPT, BYTE_OPT, TYPE_OPT);
   exit(EXIT_FAILURE);
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
   int bytes, unixCall;
   const char *file = getArgForOpt(argc, argv, FILE_OPT);
   if (file == NULL)
      incorrectUsage(argv[0]);
   if (convertToNum(getArgForOpt(argc, argv, BYTE_OPT), &bytes) == EXIT_FAILURE)
      incorrectUsage(argv[0]);
   if (convertToNum(getArgForOpt(argc, argv, TYPE_OPT), &unixCall) == EXIT_FAILURE)
      incorrectUsage(argv[0]);
   describeUsage(file, bytes, unixCall);
   return 0;
}
