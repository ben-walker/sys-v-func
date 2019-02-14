/**
 * Ben Walker
 * CIS*3110
 * 
 * Library to validate command line arguments
 */

#include "validation.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * invalidFile()
 * Returns true if file name is invalid (i.e. it doesn't
 * exist or can't be read)
 */
bool invalidFile(const char *file) {
   if (access(file, F_OK) == -1) { // check if file exists
      fprintf(stderr, "File %s not found\n", file);
      return true;
   }
   if (access(file, R_OK) == -1) { // check if file has read permissions
      fprintf(stderr, "File %s does not have read permission\n", file);
      return true;
   }
   return false;
}

/**
 * invalidBytes()
 * Returns true if bytes argument is invalid (i.e. it's less than 1)
 */
bool invalidBytes(int bytes) {
   if (bytes < 1) {
      fprintf(stderr, "Bytes cannot be less than 1\n");
      return true;
   }
   return false;
}

/**
 * invalidCallType()
 * Returns true if call type argument is invalid (i.e. it is not
 * either 0 or 1, corresponding to C and Unix respectively)
 */
bool invalidCallType(int unixCall) {
   if (unixCall != 0 && unixCall != 1) {
      fprintf(stderr, "Call type must be either 0 (C functions) or 1 (Unix I/O)\n");
      return true;
   }
   return false;
}

/**
 * argsInvalid()
 * Returns true if any of the args (file, bytes, call type)
 * are invalid
 */
bool argsInvalid(const char *file, int bytes, int unixCall) {
   return invalidFile(file) ||
      invalidBytes(bytes) ||
      invalidCallType(unixCall);
}
