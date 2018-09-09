// Name: Chenyang Fang
// Copyright 2018 Chenyang Fang

#include "./IntPair.h"

IntPair::IntPair(int x, int y) {
    x_ = x;
    y_ = y;
}

void IntPair::Get(int* x, int* y) {
    *x = x_;
    *y = y_;
}

void IntPair::Set(int x, int y) {
    x_ = x;
    y_ = y;
}
