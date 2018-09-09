// Name: Chenyang Fang
// Copyright 2018 Chenyang Fang
// this program is for testing if the Vector class works properly

// for EXIT_SUCCESS
#include <cstdlib>
// for steam output
#include<iostream>
#include "Vector.h"

using namespace vector333;
using std::cout;
using std::endl;

// create some Vectors and test on them
int main(int argc, char** argv) {
    // test constructors and the stream output
    Vector v1;
    // test default constructor
    cout << "Test default constructor, result should be (0,0,0): ";
    // another endl for formatting
    cout << v1 << endl << endl;
    // test constructor with given 3 values
    Vector v2(4, 5, 6);
    cout << "Test constructor with 3 arguments, result should be (4,5,6): ";
    cout << v2 << endl << endl;
    // test copy constructor
    Vector v3(v2);
    cout << "Test copy constructor, copy Vector(4,5,6), should be (4,5,6): ";
    cout << v3 << endl << endl;

    // test assignment
    Vector v4(2.5, 2.6, 2.7);
    v1 = v4;  // assign v4 to default Vector v1
    cout << "Test assignment, result should be (2.5,2.6,2.7): ";
    cout << v1 << endl << endl;

    // test updating assignment on vectors "+=" and "-="
    cout << "Testing += : " << endl;
    cout << v1 << " += " << v1 << "  result: ";
    v1 += v1;
    cout << v1 << endl << endl;
    cout << "Testing -= : " << endl;
    cout << v1 << " -= " << v2 << "  result:  ";
    v1 -= v2;
    cout << v1 << endl << endl;

    // test "*" operator
    Vector v5(1.5, 2, 3);
    Vector v6(3, 2.5, 0);
    cout << "Testing * : " << endl;
    cout << v5 << " * " << v6 << " = " << v5 * v6 << endl;
    double num = 2.0;
    // symmetry test
    cout << v5 << " * " << num << " = " << v5 * num << endl;
    cout << num << " * " << v5 << " = " << num * v5 << endl << endl;

    // test "+" "-" operators
    cout << "Testing + and - operators: " << endl;
    cout << v5 << " + " << v6 << " = " << v5 + v6 << endl;
    cout << v5 << " - " << v6 << " = " << v5 - v6 << endl;

    return EXIT_SUCCESS;
}
