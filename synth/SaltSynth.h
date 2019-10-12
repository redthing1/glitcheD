#pragma once

#include "Filter.h"
#include "Oscillator.h"
#include "effects/Effect.h"
#include "mod/Envelope.h"
#include <cstdint>
#include <memory>

namespace glitched {
class SaltSynth {
  public:
    std::vector<Oscillator> voices;
    std::vector<std::reference_wrapper<glitched::Effect>> effects;
    Envelope amplitudeEnvelope;
    Filter filter;
    const Parameter &pitchMod;

    SaltSynth(std::vector<Oscillator> voices, Envelope amplitudeEnvelope, Filter filter);

    std::vector<double> play(uint16_t note, double dur, double vol);
};
} // namespace glitched