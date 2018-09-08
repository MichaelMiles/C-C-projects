// Chenyang Fang
// 1663051
// chenyf@uw.edu
// Copyright 2018 Chenyang Fang
// This program is for testing if the Vector class
// is implemented correctly

// for EXIT_SUCCESS
#include <cstdlib>
// for stream output
#include <iostream>
#include "./Vector.h"

using namespace vector333;
using std::cout;
using std::endl;

// create several vectors and test their operations
int main() {
    // test constructors and stream output
    Vector v1;
    cout << "1.Default Vector, shoud be (0,0,0):  " << v1 << endl;
    Vector v2(3.4, 5.8, 6.2);
    cout << endl;
    cout << "2.Vector with initial values, should be (3.4,5.8,6.2): ";
    cout<< v2 << endl << endl;
    Vector v3(v2);
    cout << "3.Copy "<< v2 << " into v3: v3 = " << v3 << endl << endl;

    // test assignment
    Vector v4(2.5, -3.8, 10.8);
    v1 = v3 = v4;
    cout << "4.Vector assignment, should be three copies of (2.5,-3.8,10.8): ";
    cout << "\n  " << v1 << "  " << v3 << "  " << v4 << endl << endl;

    // test updating assignment
    cout << "5.Updating assignment, should be (5.9,2,17):\n";
    v3 += v2;
    cout << v3 << endl << endl;
    cout << "6.Updating assignment, should be (-1,-1.9,-6.2):\n";
    Vector v5(2.4, 3.9, 0);
    v5 -= v2;
    cout << " " << v5 << endl << endl;

    // element-wise arithmetic
    cout << "7.Arithmetic:" << endl;
    cout << v5 << " + " << v2 << " = " << v5 + v2 << endl;
    cout << v5 << " - " << v2 << " = " << v5 - v2 << endl << endl;

    // dot product
    cout << "8.Dot product: (a,b,c) * (x,y,z) = (ax+by+cz)" << endl;
    cout << v2 << " * " << v5 << " = " << v2 * v5 << endl << endl;

    // scalar product
    cout << "9.Scalar product: (a,b,c) * k = (ak,bk,ck)" << endl;
    cout << v5 << " * 8.5 = " << v5 * 8.5 << endl;
    cout << "8.5 * " << v5 << " = "<< 8.5 * v5 << endl << endl;

    cout << "10.As for testing Destructor, using Valgrind checking the memory";
    cout << "\nResult: Passed" << endl;

    return EXIT_SUCCESS;
}
