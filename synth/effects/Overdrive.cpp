//
// Created by xdrie on 10/9/19.
//
#include "Overdrive.h"

#include <utility>

glitched::Overdrive::Overdrive(Knob gain, Knob threshold)
    : gain(std::move(gain)), threshold(std::move(threshold)) {}

double glitched::Overdrive::value(double v, double t) {
    // apply gain
    v *= gain->value(0);
    if (v < -threshold->value(0)) {
        v = -threshold->value(0);
    } else if (v > threshold->value(0)) {
        v = threshold->value(0);
    }
    return v;
}
