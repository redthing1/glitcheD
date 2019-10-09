//
// Created by xdrie on 10/9/19.
//
#include "Overdrive.h"

glitched::Overdrive::Overdrive(const glitched::Parameter &gain, const glitched::Parameter &threshold)
        : gain(gain), threshold(threshold) {

}


double glitched::Overdrive::value(double v) const {
    // apply gain
    v *= gain.value(0);
    if (v < -threshold.value(0)) {
        v = -threshold.value(0);
    } else if (v > threshold.value(0)) {
        v = threshold.value(0);
    }
    return v;
}

