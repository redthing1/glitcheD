
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
#include "track/WaveHelper.h"

int main(int argc, const char *argv[]) {
    // TODO: add subcommand to select synth engine and input for NoteMachine
    
    // load audio data for granular sampling
    auto grainSource = glitched::WaveHelper::read("samp/summit.wav");
    auto sandy = glitched::SandSynth();
    sandy.grind(grainSource);

    glitched::NoteMachine noteMachine(INT16_MAX, sandy, 12);
    noteMachine.loadProgram(demo_generate_scale());
    noteMachine.execute();

    glitched::WaveHelper::save(noteMachine.audioBuffer, "out.wav");
}
