#include "args.h"
#include "numbers.h"
#include <stdio.h>
#include <stdlib.h>

const char *FILE_OPT = "-f";
const char *BYTE_OPT = "-b";
const char *TYPE_OPT = "-t";

int main(int argc, const char *argv[]) {
   int bytes, unixCall;
   const char *file = getArgForOpt(argc, argv, FILE_OPT);
   if (file == NULL) {
      /* show usage statement */
      exit(EXIT_FAILURE);
   }
   if (convertToNum(getArgForOpt(argc, argv, BYTE_OPT), &bytes) == EXIT_FAILURE) {
      /* show usage statement */
      exit(EXIT_FAILURE);
   }
   if (convertToNum(getArgForOpt(argc, argv, TYPE_OPT), &unixCall) == EXIT_FAILURE) {
      /* show usage statement */
      exit(EXIT_FAILURE);
   }
   return 0;
}
