// Name: Chenyang Fang
// ID: 1663051
// Mail: chenyf@uw.edu
// Copyright 2018 Chenyang Fang

// for type uint16_t and uint64_t
#include <inttypes.h>
// for boolean type
#include <stdbool.h>
// for printf
#include <stdio.h>
#define FIRST_PRIME 2


// With the given n, return the
// nth prime number
//
// Arguments:
//
// - n: the nth term in the sequence of primes
// - requires: n should be in proper range that can be
//             handled by uint16_t type and n > 0
//
// Returns:
//
// - the nth prime number or 0 if the given n is not valid
// - Note that NthPrime(1) shouild return 2, NthPrime(2) should return 3,
//   NthPrime(3) should return 5, and so on
//
uint64_t NthPrime(uint16_t n);
