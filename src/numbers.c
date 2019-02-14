/**
 * Ben Walker
 * CIS*3110
 * 
 * Library to convert a string to an integer
 */

#include "numbers.h"
#include <stdlib.h>
#include <limits.h>

/**
 * convertToNum()
 * Convert a string to an integer, hex or decimal
 */
int convertToNum(const char *val, int *numeric) {
   if (!val) return EXIT_FAILURE;
   char *end = NULL;
   long converted = strtol(val, &end, 0);

   // check for possible strtol errors
   if (converted == LONG_MAX || converted == LONG_MIN || end == val)
      return EXIT_FAILURE;
   *numeric = converted;
   return EXIT_SUCCESS;
}
