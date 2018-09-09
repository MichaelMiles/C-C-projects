// Chenyang Fang
// Copyright 2018 Chenyang Fang
// subclass of Coordinate, represents a 2D cartesian
// coordinate. It provides ToString method to represent
// the coordinate and Distance method that calculates the distance
// between the object and a second Cartesian point object passed
// by reference

#ifndef _CARTESIAN_H_
#define _CARTESIAN_H_

#include <string>  // for string

#include "Coordinate.h"

using namespace std;

namespace Coordinate333 {
class Cartesian : public Coordinate {
 public:
      // default constructor
      // constructor (0.0, 0.0)
      Cartesian() : x_(0.0), y_(0.0) {}
      // constructor
      // @param x the x coordinate
      // @param y the y coordinate
      // @effect construct a cartesian point (x, y)
      Cartesian(const double& x, const double& y) : x_(x), y_(y) {}
      // destructor
      virtual ~Cartesian() {}
      // overwrite ToString method from super class
      // @return string representation of this coordinate
      virtual string ToString() const;
      // calculates the distance between this coordinate
      // and the given coordinate
      // @param another another cartesian point
      // @return the distance between this cartesian point
      //         and the given another cartesian point in double
      double Distance(const Cartesian& another) const;
 private:
      double x_;  // the x-coordinate
      double y_;  // the y-coordinate
};
}  // namespace Coordinate333

#endif  // _CARTESIAN_H_
