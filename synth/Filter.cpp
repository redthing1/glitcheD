//
// Created by xdrie on 10/8/19.
//

#include "Filter.h"

glitched::Filter::Filter(glitched::FilterMode mode, const Parameter& cutoff, const Parameter& resonance)
        : mode(mode), cutoff(cutoff), resonance(resonance), buf0(0), buf1(0), feedback(0) {
}

void glitched::Filter::calculateFeedback(double t) {
    feedback = resonance.value(t) + resonance.value(t) / (1 - cutoff.value(t));
}

double glitched::Filter::process(double input, double t) {
    buf0 += cutoff.value(t) * (input - buf0 + feedback * (buf0 - buf1));
    buf1 += cutoff.value(t) * (buf0 - buf1);
    switch (mode) {
        case FilterMode::LowPass:
            return buf1;
        case FilterMode::HighPass:
            return input - buf0;
        case FilterMode::BandPass:
            return buf0 - buf1;
        default:
            return 0;
    }
}
