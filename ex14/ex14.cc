// Chenyang Fang
// Copyright@2018 Chenyang Fang
// This is for testing Polar and Cartesian coordinates' implementation

#include <cstdio>  // for EXIT_SUCCESS
#include <cmath>  // for M_PI
#include <iostream>  // for cout, endl etc.

#include "Polar.h"
#include "Cartesian.h"

using namespace std;
using namespace Coordinate333;

int main() {
    // construct a few coordinates for testing
    Cartesian c1;  // default value
    Polar p1;  // default value;
    Cartesian c2(0, 4);
    Cartesian* c3 = new Cartesian(3, 0);
    Polar* p2 = new Polar(10.8, 90 * M_PI / 180);

    cout << "We have:" << endl;
    cout << "c1: " << c1.ToString() << endl;
    cout << "c2: " << c2.ToString() << endl;
    cout << "c3: " << c3->ToString() << endl;
    cout << "p1: " << p1.ToString() << endl;
    cout << "p2: " << p2->ToString() << endl;

    cout << endl << "Distance: " << endl;
    cout << "c2 to c3: " << c3->Distance(c2) << endl;
    cout << "p1 to p2: " << p1.Distance(*p2) << endl;

    delete c3;
    delete p2;
    return EXIT_SUCCESS;
}
