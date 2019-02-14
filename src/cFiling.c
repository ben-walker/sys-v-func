#include "cFiling.h"
#include <stdio.h>

void cReadFile(const char *file, int bytes) {
   FILE *fp = fopen(file, "r");

   if (bytes == 1)
      while (fgetc(fp) != EOF);
   else {
      char buff[bytes];
      while (fread(buff, 1, bytes, fp) == bytes);
   }

   fclose(fp);
}
