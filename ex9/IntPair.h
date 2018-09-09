// Name: Chenyang Fang
// Copyright 2018 Chenyang Fang
// This file defines an IntPair class
// which stores a pair of integers

#ifndef _INTPAIR_H
#define _INTPAIR_H

// An IntPair class represents a pair of integers
// it provides methods for accessing and setting
// the values inside the pair
class IntPair {
 public:
    // Construct a pair of integers
    // with the values of the given integers
    IntPair(int x, int y);

    // Gets the values stored in this pair
    void Get(int* x, int* y);

    // Sets the values stored in this pair
    // with the values of the given integers
    void Set(int x, int y);

 private:
    // members of integers pair
    int x_;
    int y_;
};


#endif
