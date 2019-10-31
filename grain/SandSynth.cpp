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
    //    for (int i = 0; i < sampleLength; i++) {
    //        int grainSeq = i / samplesPerPeriod; // start new grains at every frequency cycle
    //        int grainPos = i % grainLength;
    //        buf.l[i] = grains.l[grainStart(grainSeq) + grainPos];
    //        buf.r[i] = grains.r[grainStart(grainSeq) + grainPos];
    //    }

    int grainsInSample = sampleLength / frameSpace;
    int grainFrame = frameRamp * 2 + frameHold;
    int concurrentGrains = grainFrame / frameSpace; // the maximum number of grains playing at a time
    double grainMix = 1.0 / concurrentGrains; // grain mix volume factor
    for (int g = 0; g < grainsInSample; g++) { // for each grain
        // figure out when the grain starts
        int timeGrainStart = g * frameSpace;
        // copy samples and ramp
        for (int i = 0; i < grainFrame; i++) {
            int noteSamplePos = timeGrainStart + i;
            if (noteSamplePos > sampleLength - 1) {
                break;
            }

            // calculate linear ramp volume
            double v = 1.0;
            if (i < frameRamp) { // up ramp
                v = static_cast<double>(i) / frameRamp;
            }
            if (i > frameRamp + frameHold) { // down ramp
                v = static_cast<double>(i - (frameRamp + frameHold)) / frameRamp;
            }

            // mix the sample into the buffer
//            int grainSeq = i / samplesPerPeriod; // start new grains at every frequency cycle
            int grainSeq = g;
            int grainPos = i % grainLength;
            buf.l[noteSamplePos] += grains.l[grainStart(grainSeq) + grainPos] * v;
            buf.r[noteSamplePos] += grains.r[grainStart(grainSeq) + grainPos] * v;
        }
    }

    return buf;
}
void SandSynth::grind(StereoSample sample) {
    grains = sample;
    auto sampleLength = sample.size();
    // split into tiny grains
    grainLength = 0.005 * SAMPLE_RATE;
    // set spaces between grain sampling
    grainDist = 0.0025 * SAMPLE_RATE;

    // set grain frame playback parameters
    frameRamp = 0.004 * SAMPLE_RATE;
    frameHold = 0.002 * SAMPLE_RATE;
    frameSpace = 0.008 * SAMPLE_RATE;
}
size_t SandSynth::grainStart(int seq) {
    size_t grainWidth = grainLength * seq;
    size_t grainSpacing = grainDist * seq;
    int grainPos = grainWidth + grainSpacing;
    return grainPos % grains.size();
}
}