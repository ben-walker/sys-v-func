#include "args.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

const char *FILE_ARG = "-f";

int indexOfOption(int argc, const char *argv[], const char *arg) {
   int i = 0;
   for (; i < argc; i += 1)
      if (strcmp(argv[i], arg) == 0)
         break;
   return i < argc - 1
      ? i + 1
      : -1;
}

char *getTargetFile(int argc, const char *argv[]) {
   int index = indexOfOption(argc, argv, FILE_ARG);
   if (index == -1)
      return NULL;
   char *target = strdup(argv[index]);
   if (!target) {
      perror("strdup");
      exit(EXIT_FAILURE);
   }
   return target;
}
