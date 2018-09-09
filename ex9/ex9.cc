// Name: Chenyang Fang
// Copyright 2018 Chenyang Fang
// This file tests if IntPair
// is pass-by-value or passe-by-reference

// for EXIT_SUCCESS
#include <cstdlib>
// for std::cout etc.
#include <iostream>

#include "./IntPair.h"


// Using Get and Set methods to
// modify the internal state of the given
// IntPair object by adding 1 to each number
// stored in the given IntPair
void test(IntPair pair) {
    int a;
    int b;

    // obtain the values stored
    // in the pair
    pair.Get(&a, &b);
    // increment a and b
    a++;
    b++;
    // reset the values in the pair object
    pair.Set(a, b);
}

int main(int argc, char** argv) {
    // construct a new IntPair
    int a = 4;
    int b = 7;
    IntPair pair(a, b);

    // test if functions changes IntPair
    test(pair);
    // check if the pair object
    // has been modifed by test function
    int x;
    int y;
    pair.Get(&x, &y);

    if ((x == a) && (y == b)) {
        // pair has not been modifed
        // and thus IntPair is pass-by-value
        std::cout << "Is pass by value" << std::endl;
    } else {
        // pair has been modifed
        // and thus IntPair is pass-by-reference
        std::cout << "Is pass by reference" << std::endl;
    }
    return EXIT_SUCCESS;
}
