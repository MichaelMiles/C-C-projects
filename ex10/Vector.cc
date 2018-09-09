// Name: Chenyang Fang
// Copyright 2018 Chenyang Fang

// for stream output
#include <iostream>
#include "Vector.h"

// implementation of Vector

namespace vector333 {

Vector::~Vector() {}

Vector& Vector::operator=(const Vector& v) {
    // check if the given argument is this object
    // do nothing if they are the same
    if (this != &v) {
        this->x_ = v.x_;
        this->y_ = v.y_;
        this->z_ = v.z_;
    }
    return *this;
}

Vector& Vector::operator+=(const Vector& v) {
    this->x_ += v.x_;
    this->y_ += v.y_;
    this->z_ += v.z_;

    return *this;
}

Vector& Vector::operator-=(const Vector& v) {
    this->x_ -= v.x_;
    this->y_ -= v.y_;
    this->z_ -= v.z_;

    return *this;
}

double operator*(const Vector& v, const Vector& k) {
    return k.x_ * v.x_ + k.y_ * v.y_ + k.z_ * v.z_;
}

Vector operator*(const Vector& v, double k) {
    return Vector(v.x_ * k, v.y_ * k, v.z_ * k);
}

Vector operator*(double k, const Vector& v) {
    return Vector(v.x_ * k, v.y_ * k, v.z_ * k);
}

std::ostream& operator<<(std::ostream &out, const Vector& v) {
    out << "(" << v.x_ << "," << v.y_ << "," << v.z_ << ")";
    return out;
}

Vector operator+(const Vector& a, const Vector& b) {
    Vector temp = a;
    temp += b;
    return temp;
}

Vector operator-(const Vector& a, const Vector& b) {
    Vector temp = a;
    temp -= b;
    return temp;
}

}  // namespace vector333
