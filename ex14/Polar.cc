// Chenyang Fang
// 1663051
// chenyf@uw.edu
// Copyright 2018 Chenyang Fang
// implementation of Polar class


#include <cmath>  // for sin and cos etc.
#include <string>  // for string
#include "Polar.h"

using namespace std;

namespace Coordinate333 {
// implement ToString
string Polar::ToString() const {
    string result("(");
    // append coordinates information
    result += to_string(r_);
    result += ", ";
    result += to_string(a_);
    result += ")";

    return result;
}

// Distance method
double Polar::Distance(const Polar& another) const {
    // use distance formula for polar coordinates
    // to calculate the distance
    double result = sqrt(pow(r_, 2) + pow(another.r_, 2) -
            2 * r_ * another.r_ * cos(a_ - another.a_));
    return result;
}


}  // namespace Coordinate333

