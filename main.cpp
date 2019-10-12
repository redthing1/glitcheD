
#include <cmath>
#include <iostream>
#include <memory>
#include <vector>

#include "constants.h"
#include "misc/songs.h"
#include "synth/Filter.h"
#include "synth/Oscillator.h"
#include "synth/SaltSynth.h"
#include "synth/effects/Delay.h"
#include "synth/effects/Overdrive.h"
#include "synth/mod/LFO.h"
#include "track/NoteMachine.h"
#include "track/SongWriter.h"

int main(int argc, const char *argv[]) {
    auto osc1 = glitched::Oscillator(glitched::Wave::Saw);
    osc1.tune = -10;
    osc1.mix = 0.5;
    auto osc2 = glitched::Oscillator(glitched::Wave::Saw);
    osc2.tune = +10;
    osc2.mix = 0.5;
    auto osc3 = glitched::Oscillator(glitched::Wave::Square);
    osc3.transpose = -12;
    auto osc_pitchMod = std::make_shared<glitched::LFO>(4.0, 0.5);
    osc1.pitchMod = osc_pitchMod;
    osc2.pitchMod = osc_pitchMod;
    auto voices = {osc1, osc2, osc3};
    auto ampEnv = glitched::Envelope(0.1f, 0.4f, 0.3f, 0.4f);
    auto cutoffMod = std::make_shared<glitched::LFO>(2.0);
    auto cutoff = glitched::Value(0.6, cutoffMod, 0.1);
    auto resonance = glitched::Value(0.40);
    auto filter = glitched::Filter(glitched::FilterMode::LowPass, cutoff, resonance);
    auto instr1 = glitched::SaltSynth(voices, ampEnv, filter);

    auto fx1_gain = std::make_shared<glitched::Value>(1.5);
    auto fx1_threshold = std::make_shared<glitched::Value>(0.8);
    auto fx1 = glitched::Overdrive(fx1_gain, fx1_threshold);
    instr1.effects.emplace_back(fx1);

//    auto fx2_time = std::make_shared<glitched::Value>(0.25);
//    auto fx2_gain = std::make_shared<glitched::Value>(1.0);
//    auto fx2 = glitched::Delay(fx2_time, fx2_gain);
//    instr1.effects.emplace_back(fx2);

    glitched::NoteMachine noteMachine(INT16_MAX, instr1, 10);
    noteMachine.loadProgram(demo_stardustCrusaders);
    noteMachine.execute();

    glitched::SongWriter songWriter(noteMachine.audioBuffer.size());
    songWriter.insert(0, noteMachine.audioBuffer);
    songWriter.save("out.wav");
}
