
 #include <dirent.h>
   // for EXIT_FAILURE
      // and EXIT_SUCCESS
        #include <stdlib.h>
          // for printf, etc
            #include <stdio.h>
              // for boolean type
                #include <stdbool.h>
                  // for strcmp
                    #include <string.h>
                      // for uint64_t type etc
                        #include <inttypes.h>
                          // for read()
                            #include <unistd.h>
                              // for open(), close()
                                #include <fcntl.h>
                                  // for directory operations
                                    #include <dirent.h>
void print(char* filename, char* dirName) {
    uint64_t length = strlen(dirName) + strlen(filename) + 2;
    char full_path[length];
             strncat(full_path, dirName, strlen(dirName));
               full_path[strlen(dirName)] = '/';
                 strncat(full_path, filename, strlen(filename) + 1);

   fprintf(stdout, "%s\n",full_path );
   int a = 0;
   if ('\0' == dirName[strlen(dirName)]) {
    a = 30;
   }
   fprintf(stdout, "%d", a);
}

int main(int argc, char** argv) {
    print("abc", "def");

}
