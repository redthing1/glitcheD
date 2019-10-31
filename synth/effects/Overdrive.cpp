//
// Created by xdrie on 10/9/19.
//
#include "Overdrive.h"

#include <utility>

glitched::Overdrive::Overdrive(Knob gain, Knob threshold)
    : gain(std::move(gain)), threshold(std::move(threshold)) {}

double glitched::Overdrive::value(double v, double t) {
    // apply gain
    t = 0; // use default zero value
    v *= gain->value(t);
    if (v < -threshold->value(t)) {
        v = -threshold->value(t);
    } else if (v > threshold->value(t)) {
        v = threshold->value(t);
    }
    return v;
}
