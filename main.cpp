
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
#include "misc/songs.h"

int main(int argc, const char *argv[]) {
    auto osc1 = glitched::Oscillator(glitched::Wave::Saw);
    auto osc2 = glitched::Oscillator(glitched::Wave::Triangle);

    auto test440Buf = osc1.play(glitched::note(49), 1, 0.9f);

    auto instr1 = glitched::Instrument({osc1, osc2}, glitched::Envelope(0.05f, 0.2f, 1.0f, 0.4f));

    glitched::NoteMachine noteMachine(INT16_MAX, instr1, 32);
    noteMachine.loadProgram(demo_stardustCrusaders);
    noteMachine.execute();

    glitched::SongWriter songWriter(noteMachine.audioBuffer.size());
    songWriter.insert(0, noteMachine.audioBuffer);
    songWriter.save("out.wav");
}

