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

int main(int argc, const char *argv[]) {
   int bytes, unixCall;
   const char *file = getArgForOpt(argc, argv, FILE_OPT);
   if (file == NULL)
      incorrectUsage(argv[0]);
   if (convertToNum(getArgForOpt(argc, argv, BYTE_OPT), &bytes) == EXIT_FAILURE)
      incorrectUsage(argv[0]);
   if (convertToNum(getArgForOpt(argc, argv, TYPE_OPT), &unixCall) == EXIT_FAILURE)
      incorrectUsage(argv[0]);
   return 0;
}
