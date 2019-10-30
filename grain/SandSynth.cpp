//
// Created by xdrie on 10/30/19.
//
#include "SandSynth.h"
#include "../defs.h"

namespace glitched {
Sample SandSynth::play(uint16_t note, double dur, double vol) {
    Sample buf = Sample();
    buf.resize(dur * SAMPLE_RATE);
    auto sampleLength = dur * SAMPLE_RATE;

    return buf;
}
void SandSynth::grind(Sample sample) {

}
}