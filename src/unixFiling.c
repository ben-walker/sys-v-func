#include "unixFiling.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void unixReadFile(const char *file, int bytes) {
   int fd = open(file, O_RDONLY);
   if (fd == -1) {
      perror("open");
      exit(EXIT_FAILURE);
   }

   char buff[bytes];
   while (read(fd, buff, bytes) != 0);

   if (close(fd) == -1) {
      perror("close");
      exit(EXIT_FAILURE);
   }
}
