//
// Created by xdrie on 10/8/19.
//

#include "Filter.h"

glitched::Filter::Filter(glitched::FilterMode mode, double cutoff, double resonance)
        : mode(mode), cutoff(cutoff), resonance(resonance), buf0(0), buf1(0) {

}

void glitched::Filter::calculateFeedback() {
    feedback = resonance + resonance / (1 - cutoff);
}

double glitched::Filter::process(double input) {
    buf0 += cutoff * (input - buf0);
    buf1 += cutoff * (buf0 - buf1);
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
