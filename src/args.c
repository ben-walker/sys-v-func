/**
 * Ben Walker
 * CIS*3110
 * 
 * Library to find an argument that succeeds an option in
 * an argument list
 */

#include "args.h"
#include <stdlib.h>
#include <string.h>

/**
 * indexOfArg()
 * Returns the index of an argument that succeeds
 * a given option in an argument array
 */
int indexOfArg(int argc, const char *argv[], const char *opt) {
   int i = 0;
   for (; i < argc; i += 1)
      if (strcmp(argv[i], opt) == 0) // loop until we find the option
         break;
   return i < argc - 1 // is i the index of the last element?
      ? i + 1 // if not, return the index of the next array element
      : -1; // if it is, indicate that we didn't find it
}

/**
 * getArgForOpt()
 * Returns a pointer to an argument that succeeds a
 * given option in an argument array
 */
const char *getArgForOpt(int argc, const char *argv[], const char *opt) {
   int index = indexOfArg(argc, argv, opt);
   return index == -1
      ? NULL
      : argv[index];
}
