#pragma once

#include "Parameter.h"
#include <cmath>

namespace glitched {
class Envelope : public Parameter {
  private:
    static double logEase(double lower, double upper, double exponent, double x);

    const double ENVELOPE_EXP = 3.0;
    const double ENVELOPE_MIN = 0.0001;
    const double ENVELOPE_MAX = 1.0;

  public:
    double A, D, S, R;

    Envelope(double a, double d, double s, double r);

    double calc(bool held, double t) const;
    double value(double t) const override;
};
} // namespace glitched