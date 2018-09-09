// Name: Chenyang Fang
// Copyright 2018 Chenyang Fang

// for uint64_t and int64_t etc.
#include <inttypes.h>
// for cin and cout etc.
#include <iostream>
// for EXIT_FAILURE, EXIT_SUCCESS
#include <cstdlib>


using namespace std;

// check if the given factor is a factor
// of the given num
// require: factor > 0 && num > 0
// return true if the given factor is a factor
// of the given num
// return false otherwise
bool isFactor(uint64_t num, uint64_t factor) {
    return (num % factor) == 0;
}

// Ask for a positive integer and prints out
// all factors of that integer
int main(int argc, char** argv) {
    // for storing the input
    int64_t number;
    // prompt the user to type in some postive integer for factorize
    // and store that integer
    cout << "Which positive integer would you like me to factorize? ";
    cin >> number;

    // check if the input is valid
    if (cin.fail() || (number <= 0)) {
        // bad input case
        cerr << "Sorry, your input is not valid" << endl;
        return EXIT_FAILURE;
    }
    // convert to uint64_t type
    uint64_t num = number;

    // print out all the factors of num
    for (uint64_t factor = 1; factor <= num; factor++) {
        if (isFactor(num, factor)) {
            cout << factor << (factor == num ? "" : " ");
        }
    }
    // for formatting
    cout << endl;
    return EXIT_SUCCESS;
}
