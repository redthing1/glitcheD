//
// Created by xdrie on 10/8/19.
//
#include <cmath>
#include "LFO.h"
#include "../../constants.h"

glitched::LFO::LFO(double freq)
        : freq(freq) {
}

double glitched::LFO::value(double t) const {
    return std::sin(freq * t * tau);
}
