
#include <cmath>
#include <iostream>
#include <memory>
#include <vector>

#include "defs.h"
#include "grain/SandSynth.h"
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
    auto instr1 = glitched::SandSynth();

    glitched::NoteMachine noteMachine(INT16_MAX, instr1, 10);
    noteMachine.loadProgram(demo_stardustCrusaders);
    noteMachine.execute();

    glitched::SongWriter songWriter(noteMachine.audioBuffer.size());
    songWriter.insert(0, noteMachine.audioBuffer);
    songWriter.save("out.wav");
}
