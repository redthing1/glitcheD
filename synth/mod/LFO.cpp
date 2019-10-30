//
// Created by xdrie on 10/8/19.
//
#include "LFO.h"
#include "../../defs.h"
#include <cmath>

glitched::LFO::LFO(double freq) : LFO(freq, 1.0) {}

double glitched::LFO::value(double t) const {
    return std::sin(freq * t * tau) * amp;
}

glitched::LFO::LFO(double freq, double amp) : freq(freq), amp(amp) {}
