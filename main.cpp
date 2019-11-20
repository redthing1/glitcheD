
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
#include "util/toml.h"

int main(int argc, const char *argv[]) {
    if (argc < 4) {
        std::cout << "Usage:" << std::endl;
        std::cout << "  ./glitcheD <engine> <input> <output>" << std::endl;
        return -1;
    }
    std::shared_ptr<glitched::Instrument> instr;
    std::string engine_arg(argv[1]);
    std::string input_arg(argv[2]);
    std::string output_arg(argv[3]);
    std::string config_file = "glitched.toml";
    std::ifstream cfs(config_file);
    toml::ParseResult pr = toml::parse(cfs);

    if (!pr.valid()) {
        std::cout << config_file << ": toml parse error: " << pr.errorReason << std::endl;
        return -2;
    }

    if (engine_arg == "salt") {
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
        auto salty = std::make_shared<glitched::SaltSynth>(voices, ampEnv, filter);
        instr = salty;
    } else if (engine_arg == "sand") {
        // load audio data for granular sampling
        auto grainSource = glitched::WaveHelper::read("samp/summit.wav");
        auto sandy = std::make_shared<glitched::SandSynth>();
        sandy->grind(grainSource);
        instr = sandy;
    }
    std::cout << "[g] synth engine: " << engine_arg << std::endl;
    std::cout << "[g] input file: " << input_arg << std::endl;
    std::cout << "[g] output file: " << output_arg << std::endl;

    glitched::NoteMachine noteMachine(INT16_MAX, *instr.get(), 12);
    noteMachine.loadProgram(demo_generate_scale());
    noteMachine.execute();

    glitched::WaveHelper::save(noteMachine.audioBuffer, output_arg);
}
