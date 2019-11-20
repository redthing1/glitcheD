//
// Created by xdrie on 11/19/19.
//
#pragma once

#include "../synth/Oscillator.h"

glitched::Wave parseWave(std::string wave) {
    if (wave == "sin") return glitched::Wave::Sine;
    else if (wave == "sqr") return glitched::Wave::Square;
    else if (wave == "saw") return glitched::Wave::Saw;
    else if (wave == "tri") return glitched::Wave::Triangle;
    else if (wave == "noi") return glitched::Wave::Noise;
    throw std::runtime_error("invalid wave");
}