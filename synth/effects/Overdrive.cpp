//
// Created by xdrie on 10/9/19.
//
#include "Overdrive.h"

#include <utility>

glitched::Overdrive::Overdrive(std::shared_ptr<Parameter> gain, std::shared_ptr<Parameter> threshold)
    : gain(std::move(gain)), threshold(std::move(threshold)) {}

double glitched::Overdrive::value(double v) const {
    // apply gain
    v *= gain->value(0);
    if (v < -threshold->value(0)) {
        v = -threshold->value(0);
    } else if (v > threshold->value(0)) {
        v = threshold->value(0);
    }
    return v;
}
