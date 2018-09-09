// Name: Chenyang Fang
// Copyright 2018 Chenyang Fang
// This file represents a Vector which contains magnitudes of 3 directions
// x_, y_ and z_. It provides several constructor and overload several operators

#ifndef _VECTOR_H_
#define _VECTOR_H_
// for stream output
#include <iostream>

namespace vector333 {
// definition of 3D Vector
class Vector {
 public:
    // constructors
    // default constructor: create vector (0, 0, 0)
    Vector()
        : x_(0.0), y_(0.0), z_(0.0) {}
    // construct vector (x, y, z)
    Vector(float x, float y, float z)
        : x_(x), y_(y), z_(z) {}
    // copy constructor
    // copy all the fields
    Vector(const Vector& v)
        : x_(v.x_), y_(v.y_), z_(v.z_) {}
    // destructor
    ~Vector();
    // overload the "=" "+=" "-=" "*"operators
    // Assignment for Vectors
    Vector& operator=(const Vector& v);
    // add a Vector to this Vector: element-by-element addition of
    // the vector components
    Vector& operator+=(const Vector& v);
    // substract a Vector from this Vector: element-by-element substraction
    // of the vector components
    Vector& operator-=(const Vector& v);
    // multiplication: return the result inner product(dot product) of
    // components of these two Vectors in double
    friend double operator*(const Vector& v, const Vector& k);
    // friend functions for overloading "*" operator
    // multiply the given double k with each field in the given Vector
    // for example, if the given Vector is (a, b, c)
    // return a new Vector(a*k, b*k, c*k)
    friend Vector operator*(const Vector& v, double k);
    friend Vector operator*(double k, const Vector& v);
    // friend function for overloading "<<"
    // write Vector v(a, b, c) for example to stream out as "(a,b,c)"
    friend std::ostream& operator<<(std::ostream &out, const Vector& v);

 private:
    // three variables to represent magnitudes in
    // in the x, y, and z directions of this Vector
    float x_;
    float y_;
    float z_;
};

// overload "+" and "-" operators
// perform element-by-element addition or substraction of
// the components of the given two Vectors and return the
// result as a new Vector
Vector operator+(const Vector& a, const Vector& b);
Vector operator-(const Vector& a, const Vector& b);

}  // namespace vector333

#endif  // _VECTOR_H_
