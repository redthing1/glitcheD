#pragma once

#include <cstdint>

static const double tau = 6.28318530717958; // 2*pi = 360˚ = one full cycle
static const uint16_t SAMPLE_RATE = 44100;
static const uint16_t BIT_DEPTH = 24;

// note/release mix
namespace glitched {
    static const double MIX_THRESHOLD = 0.9;
    static const double MIX_NOTE = 0.7;
    static const double MIX_RELEASE = 0.4;
}
