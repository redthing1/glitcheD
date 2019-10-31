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

    int frameSpace = SAMPLE_RATE / freq;
    int grainsInSample = sampleLength / frameSpace;
    int grainFrame = frameRamp * 2 + frameHold;
    int concurrentGrains = (grainFrame / frameSpace) + 1; // the maximum number of grains playing at a time
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
            int grainSeq = g;
            int grainPos = i % grainLength;
            buf.l[noteSamplePos] += grains.l[grainStart(grainSeq) + grainPos] * v * grainMix;
            buf.r[noteSamplePos] += grains.r[grainStart(grainSeq) + grainPos] * v * grainMix;
        }
    }

    return buf;
}
void SandSynth::grind(StereoSample sample) {
    grains = sample;
    auto sampleLength = sample.size();
    // split into tiny grains

    // set spaces between grain sampling
    grainDist = 0.001 * SAMPLE_RATE;
    // set grain frame playback parameters
    frameRamp = 0.0005 * SAMPLE_RATE;
    frameHold = 0.0005 * SAMPLE_RATE;
    grainLength = frameRamp * 2 + frameHold;
}
size_t SandSynth::grainStart(int seq) {
    size_t grainWidth = grainLength * seq;
    size_t grainSpacing = grainDist * seq;
    int grainPos = grainWidth + grainSpacing;
    return grainPos % grains.size();
}
}