#pragma once

#include <cstdint>
#include "Oscillator.h"
#include "mod/Envelope.h"
#include "Filter.h"

namespace glitched {
    class Instrument {
    public:
        std::vector<Oscillator> voices;
        Envelope amplitudeEnvelope;
        Filter filter;

        Instrument(std::vector<Oscillator> voices, Envelope amplitudeEnvelope, Filter filter);

        std::vector<double> play(uint16_t note, double dur, double vol);
    };
}