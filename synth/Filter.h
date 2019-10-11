//
// Created by xdrie on 10/8/19.
//

#pragma once

#include "mod/Parameter.h"

namespace glitched {
enum FilterMode { LowPass, HighPass, BandPass };

class Filter {
    double feedback;
    double buf0, buf1;

    inline void calculateFeedback(double t);

  public:
    FilterMode mode;
    const Parameter &cutoff;
    const Parameter &resonance;

    explicit Filter(FilterMode mode, const Parameter &cutoff, const Parameter &resonance);
    double process(double input, double t);
};
} // namespace glitched