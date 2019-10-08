#include "Envelope.h"

glitched::Envelope::Envelope(double a, double d, double s, double r) : A(a), D(d), S(s), R(r) {}

double glitched::Envelope::calculateMultiplier(double start, double end, double time) {
    double mult = 1.0 + (std::log(start) - std::log(end)) * time;
    return mult;
}

double glitched::Envelope::calc(bool held, double t) {
    double level = 0;
    if (held) {
        if (t < A) {
            // attack
            level = (t / A);
        } else if (t < (A + D)) {
            // decay
            level = 1;
        } else {
            // sustain
            level = S;
        }
    } else {
        // release
        level = (1 - (t / R)) * S;
    }
    return level;
}

