#include "args.h"
#include <stdlib.h>
#include <string.h>

int indexOfOpt(int argc, const char *argv[], const char *arg) {
   int i = 0;
   for (; i < argc; i += 1)
      if (strcmp(argv[i], arg) == 0)
         break;
   return i < argc - 1
      ? i + 1
      : -1;
}

const char *getArgForOpt(int argc, const char *argv[], const char *opt) {
   int index = indexOfOpt(argc, argv, opt);
   return index == -1
      ? NULL
      : argv[index];
}
