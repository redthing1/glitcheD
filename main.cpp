
#include <cmath>
#include <iostream>
#include <memory>
#include <vector>

#include "constants.h"
#include "track/SongWriter.h"
#include "synth/Oscillator.h"
#include "util/Tuning.h"
#include "synth/Instrument.h"
#include "track/NoteMachine.h"

int main(int argc, const char *argv[]) {
    auto osc1 = glitched::Oscillator(glitched::Wave::Sine);
    auto osc2 = glitched::Oscillator(glitched::Wave::Square);

    auto test440Buf = osc1.play(glitched::note(49), 1, 0.7f);

    auto instr1 = glitched::Instrument({osc1, osc2}, glitched::Envelope(0.05f, 0.2f, 0.7f, 0.2f));

    std::vector<uint8_t> songProgram = {
            glitched::NoteMachine::VEL, 96,
            glitched::NoteMachine::DUR, 16,
            glitched::NoteMachine::PLAY, 49,
            glitched::NoteMachine::PLAY, 49,
            glitched::NoteMachine::PLAY, 52,
            glitched::NoteMachine::PLAY, 56,
            glitched::NoteMachine::RET,
    };

    glitched::NoteMachine noteMachine(INT16_MAX, instr1, 16);
    noteMachine.loadProgram(songProgram);
    noteMachine.execute();

    glitched::SongWriter songWriter(noteMachine.audioBuffer.size());
    songWriter.insert(0, noteMachine.audioBuffer);
    songWriter.save("out.wav");
}

