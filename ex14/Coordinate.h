// Chenyang Fang
// Copyright 2018 Chenyang Fang
// This file define a purely virtual class
// called Coordinate that represents an abstract
// 2-dimisional coordinate.

#ifndef _COORDINATE_H_
#define _COORDINATE_H_

#include <string>  // for string

using namespace std;

namespace Coordinate333 {

class Coordinate {
 public:
    // destructor
    virtual ~Coordinate() {}
    // @returns a string representation of this coordinate
    virtual string ToString() const = 0;
};
}  // namespace Coordinate333

#endif  // _COORDINATE_H_
