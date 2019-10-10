
#include <cmath>
#include <iostream>
#include <memory>
#include <vector>

#include "constants.h"
#include "track/SongWriter.h"
#include "synth/Oscillator.h"
#include "synth/Filter.h"
#include "util/Tuning.h"
#include "synth/Instrument.h"
#include "track/NoteMachine.h"
#include "misc/songs.h"
#include "synth/mod/LFO.h"
#include "synth/effects/Overdrive.h"

int main(int argc, const char *argv[]) {
    auto osc1 = glitched::Oscillator(glitched::Wave::Saw);
    osc1.tune = -10;
    osc1.mix = 0.5;
    auto osc2 = glitched::Oscillator(glitched::Wave::Saw);
    osc2.tune = +10;
    osc2.mix = 0.5;
    auto osc3 = glitched::Oscillator(glitched::Wave::Square);
    auto voices = {
            osc1,
            osc2,
            osc3
    };
    auto ampEnv = glitched::Envelope(0.05f, 0.2f, 0.7f, 0.4f);
    auto cutoffMod = std::make_shared<glitched::LFO>(8.0);
    auto cutoff = glitched::Value(0.6, cutoffMod);
    cutoff.modAmount = 0.2;
    auto resonance = glitched::Value(0.40);
    auto filter = glitched::Filter(glitched::FilterMode::LowPass, cutoff, resonance);
    auto instr1 = glitched::Instrument(voices, ampEnv, filter);

    auto fx1_gain = glitched::Value(1.5);
    auto fx1_threshold = glitched::Value(0.8);
    auto fx1 = std::make_unique<glitched::Overdrive>(fx1_gain, fx1_threshold);
//    fx1->enabled = false;
    instr1.effects.emplace_back(std::move(fx1));

    glitched::NoteMachine noteMachine(INT16_MAX, instr1, 32);
    noteMachine.loadProgram(demo_stardustCrusaders);
    noteMachine.execute();

    glitched::SongWriter songWriter(noteMachine.audioBuffer.size());
    songWriter.insert(0, noteMachine.audioBuffer);
    songWriter.save("out.wav");
}

