#pragma once

#include "mod/Parameter.h"
#include <vector>
namespace glitched {
static const int PARTIALS = 64;

enum Wave {
    Sine,
    Square,
    Saw,
    Triangle,
    Noise,
};

class Oscillator {
    std::vector<double> genSin(double freq, double dur, double amp = 1.0, double phase = 0);
    std::vector<double> genSqr(double freq, double dur, double amp = 1.0);
    std::vector<double> genSaw(double freq, double dur, double amp = 1.0, double factor = 1.0);
    std::vector<double> genTri(double freq, double dur, double amp = 1.0);
    std::vector<double> genNoise(double dur, double amp = 1.0);

  public:
    Wave wave;
    int tune;
    double mix;

    Parameter &pitchMod;

    explicit Oscillator(Wave wave);

    std::vector<double> play(double freq, double dur, double amp);
};
} // namespace glitched
