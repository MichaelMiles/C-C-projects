// Name: Chenyang Fang
// ID: 1663051
// email: chenyf@uw.edu
// Copyright 2018 Chenyang Fang

#include "NthPrime.h"

// Helper function
// return TRUE if the given num is a Prime number
// FALSE otherwise
//
// Argument:
//
// - num: the number we need to determine if is Prime
// - requires: num is in proper range
//
// Returns:
//
// - TRUE if the given num is Prime, FALSE otherwise
bool isPrime(uint64_t num) {
    for (uint64_t i = 2; i < num; i ++) {
        if (num % i == 0) {
            // num is divisible by some
            // number between 2 and itself(not included)
            return false;
         }
    }
    // num is a prime
    return true;
}

uint64_t NthPrime(uint16_t n) {
    // check the validity of given n
    if (n == 0) {
        printf("n cannot be 0\n");
        return 0;
    }
    // keep tracking of how many primes we have found
    uint16_t count = 0;
    // we start with first prime number
    uint64_t num = FIRST_PRIME;
    while (true) {
        if (isPrime(num)) {
            // update count
            count++;
        }

        if (count == n) {
            // we have found nth prime
            return num;
        } else {
            // move on to check next number
            num++;
        }
    }
}
