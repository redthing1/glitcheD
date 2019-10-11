#pragma once

#include <cstdint>

namespace glitched {
    double note(uint16_t note);
    double detune(double freq, int cents);
}