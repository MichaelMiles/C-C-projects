// Name: Chenyang Fang
// Copyright 2018 Chenyang Fang

// for printf
#include <stdio.h>
// for uint16_t and uint64_t
#include <inttypes.h>
// for testing NthPrime
#include "NthPrime.h"
// for EXIT_SUCCESS and EXIT_FAILURE
#include <stdlib.h>
// define the test samples size
#define SIZE 10


// Test if NthPrime return the correct Nth Prime
// Print out the messages for users to notify if
// the test passed or failed
int main(int argc, char** argv) {
    // initialize our test samples
    uint64_t samples[] = {2, 3, 4, 7, 11, 13, 17, 19, 23, 29};
    // testing if NthPrime return the correct values
    for (uint16_t index = 1; index <= SIZE; index++) {
        if (NthPrime(index) != samples[index - 1]) {
            // some value does not match
            printf("Some value does not match, the NthPrime fails\n");
            return EXIT_FAILURE;
        }
        printf("Test Passed!\n");
        return EXIT_SUCCESS;
    }
}
