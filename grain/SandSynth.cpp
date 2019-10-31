//
// Created by xdrie on 10/30/19.
//
#include "SandSynth.h"
#include "../defs.h"
#include "../util/Tuning.h"

namespace glitched {
glitched::StereoSample SandSynth::play(uint16_t note, double dur, double vol) {
    StereoSample buf = StereoSample();
    buf.resize(dur * SAMPLE_RATE);
    int sampleLength = dur * SAMPLE_RATE;
    auto freq = glitched::note(note);
    auto samplesPerPeriod = SAMPLE_RATE / freq;

    // TODO: proper granular synthesis with envelopes and more
    // play a bunch of grains
    for (int i = 0; i < sampleLength; i++) {
        int grainSeq = i / samplesPerPeriod; // start new grains at every frequency cycle
        int grainPos = i % grainLength;
        buf.l[i] = grains.l[grainStart(grainSeq) + grainPos];
        buf.r[i] = grains.r[grainStart(grainSeq) + grainPos];
    }

    return buf;
}
void SandSynth::grind(StereoSample sample) {
    grains = sample;
    auto sampleLength = sample.size();
    // split into tiny grains
    grainLength = 0.005 * SAMPLE_RATE;
    // split into 2ms spaces
    grainSpace = 0.002 * SAMPLE_RATE;
}
size_t SandSynth::grainStart(int seq) {
    size_t grainNum = grainLength * seq;
    size_t grainSpacing = grainSpace * (seq - 1);
    int grainPos = grainNum + grainSpacing;
    return grainPos % grains.size();
}
}