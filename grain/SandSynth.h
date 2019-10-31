//
// Created by xdrie on 10/30/19.
//
#pragma once

#include "../defs.h"
#include "../synth/Instrument.h"
#include "../util/StereoSample.h"

namespace glitched {
class SandSynth : public Instrument {
  private:
    StereoSample grains;
    int grainLength = 0; // length of each sampled grain
    int grainDist = 0; // space between sampled grains
    int frameRamp = 0;
    int frameHold = 0;
    int frameSpace = 0;

    size_t grainStart(int seq); // compute the starting sample of the grain given the grain number
  public:
    void grind(StereoSample sample);
    virtual glitched::StereoSample play(uint16_t note, double dur, double vol) override;
};
}