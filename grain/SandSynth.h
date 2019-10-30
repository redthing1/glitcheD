//
// Created by xdrie on 10/30/19.
//
#pragma once

#include "../defs.h"
#include "../synth/Instrument.h"

namespace glitched {
class SandSynth : public Instrument {
  public:
    void grind(Sample sample);
    virtual Sample play(uint16_t note, double dur, double vol) override;
};
}