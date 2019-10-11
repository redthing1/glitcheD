#pragma once

#include <cstdint>
#include <memory>
#include "Oscillator.h"
#include "mod/Envelope.h"
#include "Filter.h"
#include "effects/Effect.h"

namespace glitched {
    class Instrument {
    public:
        std::vector<Oscillator> voices;
        std::vector<std::shared_ptr<glitched::Effect>> effects;
        Envelope amplitudeEnvelope;
        Filter filter;
        const Parameter& pitchMod;

        Instrument(std::vector<Oscillator> voices, Envelope amplitudeEnvelope, Filter filter);

        std::vector<double> play(uint16_t note, double dur, double vol);
    };
}