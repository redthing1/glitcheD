#include "Envelope.h"

glitched::Envelope::Envelope(double a, double d, double s, double r) : A(a), D(d), S(s), R(r) {}

double glitched::Envelope::logEase(double lower, double upper, double exponent, double x) {
    auto v1 = std::pow((x - lower) / (upper - lower), exponent);
    auto v2 = (upper - lower);
    auto ret = v1 * v2 + lower;
    return ret;
}

double glitched::Envelope::calc(bool held, double t) const {
    double level = 0;
    if (held) {
        if (t < A) {
            // attack
            level = std::pow(t / A, 1 / ENVELOPE_EXP);
        } else if (t < (A + D)) {
            // decay
            auto xVal = ((S - 1) / D) * (t - A) + 1;
            level = logEase(S - ENVELOPE_MIN, ENVELOPE_MAX, ENVELOPE_EXP, xVal);
        } else {
            // sustain
            level = S;
        }
    } else {
        // release
        auto xVal = (-S / R) * (t) + S;
        level = logEase(0, S, ENVELOPE_EXP, xVal);
    }
    return level;
}

double glitched::Envelope::value(double t) const {
    return calc(true, t);
}

