// Chenyang Fang
// Copyright 2018 Chenyang Fang
// implementation of class Vector

#include <iostream>

using namespace std;

#include "./Vector.h"

namespace vector333 {

// 3-arguments constructor
// create (x,y,z)
Vector::Vector(const float x, const float y, const float z) {
    xyz_ = new float[3];
    xyz_[0] = x;
    xyz_[1] = y;
    xyz_[2] = z;
}

// copy constructor
Vector::Vector(const Vector& cp) {
    xyz_ = new float[3];
    xyz_[0] = cp.xyz_[0];
    xyz_[1] = cp.xyz_[1];
    xyz_[2] = cp.xyz_[2];
}

// destructor
Vector::~Vector() {
    delete[] xyz_;
}

// assignment
Vector& Vector::operator=(const Vector& other) {
    // check if the other vector is the same as
    // this vector. If it is, do nothing.
    if (&other != this) {
        xyz_[0] = other.xyz_[0];
        xyz_[1] = other.xyz_[1];
        xyz_[2] = other.xyz_[2];
    }
    return *this;
}

// += and -= operator
Vector& Vector::operator+=(const Vector& other) {
    xyz_[0] += other.xyz_[0];
    xyz_[1] += other.xyz_[1];
    xyz_[2] += other.xyz_[2];
    return *this;
}

Vector& Vector::operator-=(const Vector& other) {
    xyz_[0] -= other.xyz_[0];
    xyz_[1] -= other.xyz_[1];
    xyz_[2] -= other.xyz_[2];
    return *this;
}

// friend non-member function
// * operator

// dot-product
double operator*(const Vector& v, const Vector& u) {
    return v.xyz_[0]*u.xyz_[0] + v.xyz_[1]*u.xyz_[1] + v.xyz_[2]*u.xyz_[2];
}

// scalar multiplication
Vector operator*(const Vector& v, const double k) {
    return Vector(v.xyz_[0] * k, v.xyz_[1] * k, v.xyz_[2] * k);
}

Vector operator*(const double k, const Vector& v) {
    return Vector(v.xyz_[0] * k, v.xyz_[1] * k, v.xyz_[2] * k);
}

// stream output
ostream& operator<<(ostream& out, const Vector& v) {
    out << "(" << v.xyz_[0] << "," << v.xyz_[1] << "," << v.xyz_[2] << ")";
    return out;
}

// non-member function
// + - operator
Vector operator+(const Vector& u, const Vector& v) {
    Vector temp = u;
    temp += v;
    return temp;
}

Vector operator-(const Vector& u, const Vector& v) {
    Vector temp = u;
    temp -= v;
    return temp;
}

}  // namespace vector333

