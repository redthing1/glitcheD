#pragma once

#include <cstdint>

static const double SEMITONE_RATIO = 1.0594630943592952646;
static const double CENT_RATIO = 1.0005777895065548;
namespace glitched {
    double note(uint16_t note);
    double detune(double freq, int cents);
}