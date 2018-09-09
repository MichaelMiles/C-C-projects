// Chenyang Fang
// Copyright 2018 Chenyang Fang
//

// for printf and other functions
#include <stdio.h>
// for EXIT_FAILURE and EXIT_SUCCESS
#include <stdlib.h>
// for uint64_t tyoe
#include <inttypes.h>


// Mainly used for closing the given input file
// print out the error message and exit the program
void printError(FILE* input) {
    perror("Error ");
    fclose(input);
    exit(EXIT_FAILURE);
}


// accepts a file and print out the contents of
// the given file in reverse order, character by
// character
int main(int argc, char** argv) {
    // check if exactly one argument
    if (argc != 2) {
        fprintf(stderr, "usage: ./ex6 filename");
        return EXIT_FAILURE;
    }

    // open the file
    FILE* input = fopen(argv[1], "rb");
    // check if we can open the file
    if (input == NULL) {
        // fail to open the file
        // print out error message
        fprintf(stderr, "%s -- ", argv[1]);
        perror("We could not open the file ");
        return EXIT_FAILURE;
    } else {
        // for storing character in the input file
        char inputc;
        // for getting the size of the given input file
        if (fseek(input, 0, SEEK_END) != 0) {
            // error occurs
            // exit the program
            printError(input);
        }
        // storing file's size
        uint64_t size = ftell(input);
        if (size == -1) {
            // error occurs
            // exit the program
            printError(input);
        }

        // iterating through the file in reverse order
        // and print out bytes in character
        for (uint64_t offset = size - 1; offset >= 0; offset--) {
            if (fseek(input, offset, SEEK_SET) != 0) {
                // error occurs
                printError(input);
            }
            // read byte
            if (fread((void*)&inputc, sizeof(char), 1, input) != 1) {
                // error occurs
                printError(input);
            }
            // output byte
            printf("%c", inputc);
        }
        // close the file and exit the program
        fclose(input);
        return EXIT_SUCCESS;
    }
}
