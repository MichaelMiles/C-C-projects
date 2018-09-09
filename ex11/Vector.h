// Chenyang Fang
// Copyright 2018 Chenyang Fang
// define a class Vector which represents 3-D vectors
// it stores the information of the magnitudes in the x,
// y, z directions.

#ifndef _VECTOR_H_
#define _VECTOR_H_

#include <iostream>

using namespace std;

namespace vector333 {

// represent a 3-D vector
class Vector {
 public:
    // default constructor
    // create (0,0,0)
    Vector() : xyz_(new float[3]()) { }
    // 3-arguments constructor
    // create (x,y,z)
    Vector(const float x, const float y, const float z);
    // copy constructor
    Vector(const Vector& cp);
    // destructor
    ~Vector();

    // define assignment on vectors
    // element-by-element assignment of the vector
    // components
    Vector& operator=(const Vector& other);
    // define += and -= operator
    // perform element-by-element addition or subtraction
    // of the vector components
    Vector& operator+=(const Vector& other);
    Vector& operator-=(const Vector& other);

    // friend non-member functions
    // define * operator

    // dot-product: if v is (a, b, c) and u is (x , y, z)
    // return ax+by+cz
    friend double operator*(const Vector& v, const Vector& u);
    // scalar multiplication: if v is (a, b, c)
    // return a new Vector (ak, bk, ck)
    friend Vector operator*(const Vector& v, const double k);
    friend Vector operator*(const double k, const Vector& v);

    // define stream output
    // if v is (a,b,c), it will output "(a,b,c)"
    friend ostream& operator<<(ostream& out, const Vector& v);

 private:
     // store the information of magnitudes
     // in x, y, and z directions of 3-D Vector
     float* xyz_;
};

// non-member function
// define + , - operators
// return new Vectors that are the result of element-wise sum and
// difference of two given Vectors
Vector operator+(const Vector& u, const Vector& v);
Vector operator-(const Vector& u, const Vector& v);

}  // namespace vector333

#endif  // _VECTOR_H_
