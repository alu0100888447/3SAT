//
// Created by izm20 on 24/11/17.
//

#include "../include/Sat3.h"

Sat3::Sat3() {
    neg_.reset();
    val_.reset();
    in_.reset();
}

Sat3::Sat3(bitset<3> neg, bitset<3> val, bitset<3> in) {
    neg_ = neg;
    val_ = val;
    in_ = in;
}

Sat3::Sat3(const Sat3 &cp) {
    neg_ = cp.getNeg_();
    val_ = cp.getVal_();
    in_ = cp.getIn_();
}

Sat3::~Sat3() {
    neg_.reset();
    val_.reset();
    in_.reset();
}

const bitset<3> &Sat3::getNeg_() const {
    return neg_;
}

void Sat3::setNeg_(const bitset<3> &neg_) {
    Sat3::neg_ = neg_;
}

const bitset<3> &Sat3::getVal_() const {
    return val_;
}

void Sat3::setVal_(const bitset<3> &val_) {
    Sat3::val_ = val_;
}

const bitset<3> &Sat3::getIn_() const {
    return in_;
}

void Sat3::setIn_(const bitset<3> &in_) {
    Sat3::in_ = in_;
}
