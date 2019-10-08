#pragma once

#include <cmath>
namespace glitched {
    class Envelope {
    private:
        static double calculateMultiplier(double start, double end, double time);

        const double ENVELOPE_MIN = 0.0001;
    public:
        double A, D, S, R;

        Envelope(double a, double d, double s, double r);

        double calc(bool held, double t);
    };
}