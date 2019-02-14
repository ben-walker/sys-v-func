#include "validation.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

bool invalidFile(const char *file) {
   if (access(file, F_OK) == -1) {
      fprintf(stderr, "File %s not found\n", file);
      return true;
   }
   if (access(file, R_OK) == -1) {
      fprintf(stderr, "File %s does not have read permission\n", file);
      return true;
   }
   return false;
}

bool invalidBytes(int bytes) {
   if (bytes < 1) {
      fprintf(stderr, "Bytes cannot be less than 1\n");
      return true;
   }
   return false;
}

bool invalidCallType(int unixCall) {
   if (unixCall != 0 && unixCall != 1) {
      fprintf(stderr, "Call type must be either 0 (C functions) or 1 (Unix I/O)\n");
      return true;
   }
   return false;
}

bool argsInvalid(const char *file, int bytes, int unixCall) {
   return invalidFile(file) ||
      invalidBytes(bytes) ||
      invalidCallType(unixCall);
}
