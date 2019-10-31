#pragma once

#include "../defs.h"
#include "Filter.h"
#include "Instrument.h"
#include "Oscillator.h"
#include "effects/Effect.h"
#include "mod/Envelope.h"
#include <cstdint>
#include <memory>

namespace glitched {
class SaltSynth: public Instrument {
  public:
    std::vector<Oscillator> voices;
    std::vector<std::reference_wrapper<glitched::Effect>> effects;
    Envelope amplitudeEnvelope;
    Filter filter;

    SaltSynth(std::vector<Oscillator> voices, Envelope amplitudeEnvelope, Filter filter);

    virtual glitched::Sample play(uint16_t note, double dur, double vol) override;
};
} // namespace glitched