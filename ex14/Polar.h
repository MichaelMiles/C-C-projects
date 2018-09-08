// Chenyang Fang
// 1663051
// chenyf@uw.edu
// Copyright 2018 Chenyang Fang
// subclass of Coordinate that represents a 2D polar coordinate
// it is represented as (r_, a_) where r_ is the distance and a_
// is the angle(radians) defined for polar coordinate in math

#ifndef _POLAR_H_
#define _POLAR_H_

#include <string>  // for string
#include "Coordinate.h"

using namespace std;

namespace Coordinate333 {
class Polar : public Coordinate {
 public:
    // default constructor
    // construct (0.0, 0.0)
    Polar() : r_(0.0), a_(0.0) {}
    // constructor
    // construct (r, a)
    Polar(const double& r, const double& a) :
        r_(r), a_(a) {}
    // destructor
    virtual ~Polar() {}
    // ToString method
    // @return the string representation of this Polar coordinate
    virtual string ToString() const;
    // return the distance between the given polar coordinate
    // and this polar coordinate
    // @param another another polar coordinate
    // @return the distance between this and another given polar coordinate
    //          in double
    double Distance(const Polar& another) const;
 private:
    double r_;  // the distance
    double a_;  // the angle
};
}  // namespace Coordinate333

#endif  // _POLAR_H_
