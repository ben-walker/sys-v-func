/**
 * Ben Walker
 * CIS*3110
 * 
 * Entry point for the time testing:
 * process command line arguments, show
 * usage information, call either Unix or C
 * function to read the file, and show the total
 * time taken.
 */

#include "args.h"
#include "numbers.h"
#include "validation.h"
#include "timer.h"
#include "cFiling.h"
#include "unixFiling.h"
#include <stdio.h>
#include <stdlib.h>

const char *FILE_OPT = "-f"; // option that must precede the file argument
const char *BYTE_OPT = "-b"; // option that must precede the bytes argument
const char *TYPE_OPT = "-t"; // option that must precede the "call type" argument

/**
 * incorrectUsage()
 * Prints out correct usage statement for the program
 */
void incorrectUsage(const char *programName) {
   fprintf(stderr, "Usage: %s %s filename %s bytes %s callType\n"
      "  filename: the name of the file to read\n"
      "  bytes: the number of bytes to read from filename until EOF is reached\n"
      "     Must be greater than 0\n"
      "  callType: 0 (to read filename with C library functions) or 1 (to read filename with Unix system calls)\n",
      programName, FILE_OPT, BYTE_OPT, TYPE_OPT);
}

/**
 * describeUsage()
 * Describes what will be performed on the current
 * program invocation (i.e. what type of call will be used,
 * how many bytes will be read, from what file, using what function)
 */
void describeUsage(const char *file, int bytes, int unixCall) {
   const char *callStatement = unixCall == 1
      ? "Using Unix I/O system calls to read"
      : "Using C functions to read";
   const char *byteTemplate = bytes == 1
      ? "%d byte per call from %s"
      : "%d bytes per call from %s";
   char byteStatement[256];
   snprintf(byteStatement, sizeof(byteStatement), byteTemplate, bytes, file);
   const char *readStatement = unixCall == 1
      ? "with read."
      : bytes == 1
         ? "with fgetc."
         : "with fread.";
   printf("%s %s %s\n", callStatement, byteStatement, readStatement);
}

/**
 * main()
 * Entry point for the time testing:
 * process command line arguments, show
 * usage information, call either Unix or C
 * function to read the file, and show the total
 * time taken.
 */
int main(int argc, const char *argv[]) {
   int bytes = 0, unixCall = 0, duration = 0;
   const char *file = getArgForOpt(argc, argv, FILE_OPT);

   // check if file was not specified or byte/call type arguments couldn't
   // be converted to integer
   if (
      file == NULL ||
      convertToNum(getArgForOpt(argc, argv, BYTE_OPT), &bytes) == EXIT_FAILURE ||
      convertToNum(getArgForOpt(argc, argv, TYPE_OPT), &unixCall) == EXIT_FAILURE
   ) {
      incorrectUsage(argv[0]);
      exit(EXIT_FAILURE);
   }

   // validate args, exit if invalid
   if (argsInvalid(file, bytes, unixCall))
      exit(EXIT_FAILURE);
   describeUsage(file, bytes, unixCall);

   // call the appropriate file reading library and retrieve the time taken
   if (unixCall == 1)
      duration = unixReadFile(file, bytes);
   else
      duration = cReadFile(file, bytes);
   printf("Elapsed time:   %d\n", duration);
   return 0;
}
