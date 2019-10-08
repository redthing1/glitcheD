#pragma once

#include <cstdint>
#include "Oscillator.h"
#include "Envelope.h"

class Instrument {
public:
    std::vector<Oscillator> voices;
    Envelope amplitudeEnvelope;
    Instrument(std::vector<Oscillator> voices, Envelope amplitudeEnvelope);
    std::vector<double> play(uint16_t note, double dur, double vol);
};