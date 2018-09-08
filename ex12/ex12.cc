// Chenyang Fang
// 1663051
// chenyf@uw.edu
// Copyright 2018 Chenyang Fang
// this program prompts the user to type
// in 10 doubles, reads those values and then
// print out all of them in sorted order


// for std namespace
#include <iostream>
// for EXIT_FAILURE and EXIT_SUCCESS
#include <cstdlib>
// for vector
#include <vector>
// for sort()
#include <algorithm>

using namespace std;

// for reading in a value of type T
// from the instream
// exit if detect conversion errors and EOF conditions
// @param in the istream we use for getting user's input
// @return the value that user inputs
template <typename T> T ReadValue(istream& in) {
    T value;
    in >> value;
    // checking error cases
    if (in.eof()) {
        // EOF case
        // print out error message
        // and exit the program
        cerr << "detected End of File" << endl;
        exit(EXIT_FAILURE);
    } else if (in.fail()) {
        // conversion error
        // print out error message
        // and exit the program
        cerr << "Conversion error! Please type in a double\n" << endl;
        exit(EXIT_FAILURE);
    }
    // otherwise, state is good
    // return the value from instream
    return value;
}

int main() {
    // create vector to store values from user
    vector<double> values;
    // prompt the user to type in 10 doubles
    cout << "Input 10 doubles:" << endl;
    for (int i = 0; i < 10; i++) {
        // adding each value to vector
        values.push_back(ReadValue<double>(cin));
    }
    // sort the values
    sort(values.begin(), values.end());
    cout << "Your sorted doubles are:" << endl;
    // print out all the values
    for (auto& value : values) {
        cout << value << endl;
    }

    return EXIT_SUCCESS;
}
