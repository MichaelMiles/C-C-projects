// Chenyang Fang
// 1663051
// chenyf@uw.edu
// Copyright 2018 Chenyang Fang
// Implementation of Cartesian class


#include <cmath>  // for sqrt and pow
#include <string>  // for string

#include "Cartesian.h"

using namespace std;

namespace Coordinate333 {

string Cartesian::ToString() const {
    string result("(");
    // append information of coordinates
    result += to_string(x_);
    result += ", ";
    result += to_string(y_);
    result += ")";
    return result;
}

double Cartesian::Distance(const Cartesian& another) const {
    // calculate the result using distance formula
    double xDistance = x_ - another.x_;
    double yDistance = y_ - another.y_;
    double result = sqrt(pow(xDistance, 2.0) + pow(yDistance, 2.0));
    return result;
}

}  // namespace Coordinate333
