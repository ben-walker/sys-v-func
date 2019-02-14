#include "cFiling.h"
#include <stdio.h>
#include <stdlib.h>

void cReadFile(const char *file, int bytes) {
   FILE *fp = fopen(file, "r");
   if (fp == NULL) {
      perror("fopen");
      exit(EXIT_FAILURE);
   }

   if (bytes == 1)
      while (fgetc(fp) != EOF);
   else {
      char buff[bytes];
      while (fread(buff, 1, bytes, fp) == bytes);
   }

   fclose(fp);
}
