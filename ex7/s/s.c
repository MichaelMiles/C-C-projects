#include <dirent.h>   // for directory ops
#include <errno.h>    // for errno
#include <fcntl.h>    // for open / close
#include <stdio.h>    // for printf
#include <stdlib.h>   // for EXIT_SUCCESS, malloc, free
#include <string.h>
#include <unistd.h>   // for read / write
void Usage(void) {
      fprintf(stderr, "usage: ex7 directory\n");
        exit(EXIT_FAILURE);
}
void ReadAndPrint(char *directory, char *file);
void PrintFile(char *merged_filename);

int main(int argc, char **argv) {
     if (argc != 2)
             Usage();
       DIR *d = opendir(argv[1]);
         if (d == NULL)
                 Usage();
          while (1) {
                  struct dirent *next = readdir(d);
                      if (next == NULL)
                                break;
                         int namlen = strlen(next->d_name);
                             if ((namlen >= 4) &&
                                             (strcmp(next->d_name + (namlen - 4), ".txt") == 0)) {
                                  ReadAndPrint(argv[1], next->d_name);
                                      }
                               }
           closedir(d);  return EXIT_SUCCESS;}
           void ReadAndPrint(char *directory, char *file) {  int dlen = strlen(directory);
                 int flen = strlen(file);
                   char *merged_filename = (char *) malloc(sizeof(char) * (dlen + flen + 2));
                     if (merged_filename == NULL) {
                             fprintf(stderr, "Error on malloc.\n");
                                 Usage();
                                   }
                       snprintf(merged_filename, dlen + flen + 2, "%s/%s", directory, file);
                
                       PrintFile(merged_filename);  free(merged_filename);
           }
void PrintFile(char *merged_filename) {  int fd = open(merged_filename, O_RDONLY);
      if (fd == -1) {
              perror("couldn't open file");
                  Usage();
                    }  char buf[1024];
        while (1) {
                int res = read(fd, buf, 1024);
                    if (res == 0) {      break;
                            } else if ((res == -1) && (errno != EINTR)) {      perror("read error.");
                                      Usage();
                                          } else {     if (fwrite(buf, res, 1, stdout) != 1) {
                                                      fprintf(stderr, "fwrite failed\n");
                                                              Usage();
                                                                    }
                        }
                      }
          close(fd);
}
