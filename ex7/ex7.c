// Name: Chenyang Fang
// ID: 1663051
// email: chenyf@uw.edu
// Copyright 2018 Chenyang Fang

// for opendir(), readdir()
// and closedir()
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

#define BUFFER_SIZE 100

// Print usage message and exit
void Usage() {
    fprintf(stderr, "usage: ex7 directoryname\n");
    exit(EXIT_FAILURE);
}

// check if the file with the given filename
// is a valid txt file
// note that the given filename should end with null terminator
// return true if it does
// false otherwise
bool checkTXT(char* filename) {
    uint64_t size = strlen(filename);
    if (size < 4) {
        // since the filename must end with ".txt"
        // its size of name must be at least 4 chars long
        // if not, return false
        return false;
    }
    // check if ends with ".txt"
    // create string ".txt" with null terminator
    char* txt = ".txt";
    // set a pointer pointing the the 5th char counting from the end
    // for comparison
    char* end = filename + size - 4;
    if (strcmp(txt, end) == 0) {
        // end with ".txt"
        return true;
    }
    // otherwise return false
    return false;
}


// open the given file and read the contents of it
// print out the contents
// if error happens, print out the error message
// close the given directory and exit the program
void printFile(char* filename, DIR* dir, char* dirName) {
    // create a full path
    uint64_t kLength = strlen(dirName) + strlen(filename);
    char full_path[kLength];
    // clear the arrary
    memset(full_path, '\0', sizeof(full_path));
    // append the paths
    strncat(full_path, dirName, strlen(dirName));
    strncat(full_path, filename, strlen(filename));

    int file = open(full_path, O_RDONLY);
    if (file == -1) {
        // print out error message
        // close the directory and exit
        perror("Cannot open file");
        closedir(dir);
        exit(EXIT_FAILURE);
    }
    char buffer[BUFFER_SIZE];
    // read the contents and print out the contents
    size_t num_read = read(file, buffer, BUFFER_SIZE);
    while ((num_read != 0) && (num_read != -1)) {
        if (fwrite(buffer, 1, num_read, stdout) != num_read) {
            fprintf(stderr, "error on fwrite\n");
            close(file);
            closedir(dir);
            exit(EXIT_FAILURE);
        }
        num_read = read(file, buffer, BUFFER_SIZE);
    }
    // check if error happened
    if (num_read == -1) {
        perror("Error on reading file: ");
        close(file);
        closedir(dir);
        exit(EXIT_FAILURE);
    }
    // close the file
    close(file);
}

int main(int argc, char** argv) {
    if (argc != 2) {
        Usage();
    }
    // get the directory name
    char* directName = argv[1];
    DIR* dir = opendir(directName);
    // check if open successfully
    if (dir == NULL) {
        // error happened
        // print out error message and exit
        perror("Error on open the directory");
        exit(EXIT_FAILURE);
    }
    struct dirent *nextFile = readdir(dir);
    while (nextFile != NULL) {
        if (checkTXT(nextFile->d_name)) {
            // if it is txt file
            // print out the contents
            printFile(nextFile->d_name, dir, directName);
        }
        nextFile = readdir(dir);
    }
    // close the directory
    closedir(dir);
    return EXIT_SUCCESS;
}
