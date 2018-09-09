// name: chenyf
// Copyright 2018 Chenyang Fang

#include <stdio.h>

#define PREV_DOUBLE 2.2
#define END_DOUBLE 3.3
#define ARRAY_SIZE 2

// declaration of function testDouble
void testDouble(double value);

// declaration of function testArray
void testArray(int a[ARRAY_SIZE]);

int main(int argc, char *argv[]) {
    // initiaizing for the test
    double value = PREV_DOUBLE;
    // array with random values
    int arr[] = {3, 0};

    // test Double
    testDouble(value);
    // if the value changes
    // we know that for double type
    // manipulating the parameter manipulates
    // the calling argument
    // if not changes, it is pass by value
    // print out our test result for test double
    if (value != PREV_DOUBLE) {
        printf("double: pass-by-reference");
    } else {
        printf("double: pass-by-value");
    }

    // copy of the address arr is pointing to
    // for later comparison to see if arr has been modified in test function
    int* addr = arr;
    // test Array of ints
    testArray(arr);
    // similiar to the double test
    // we test by manipulating
    // the paramter in testArray to see
    // if it changes our pointer which is
    // passed to the test function
    if (arr != addr) {
        // our pointer has been modified
        printf("\narray of ints: pass-by-reference\n");
    } else {
        printf("\narray of ints: pass-by-value\n");
    }
}

// for testing if the double is passed by reference
// or pass by value
void testDouble(double value) {
    // reassign a different value to the
    // given paramter
    value = END_DOUBLE;
}

// for testing if the array of itns is passed by
// reference or pass by value
void testArray(int a[ARRAY_SIZE]) {
    // reassign a null value to the
    // pointer passed into this function
    a =  NULL;
}
