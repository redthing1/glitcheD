
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
#include "track/NasmAssembler.h"
#include "track/NoteMachine.h"
#include "track/WaveHelper.h"
#include "util/ConfigHelper.h"
#include "util/toml.h"

int main(int argc, const char *argv[]) {
    if (argc < 4) {
        std::cout << "Usage:" << std::endl;
        std::cout << "  ./glitched <engine> <input> <output>" << std::endl;
        return -1;
    }
    std::shared_ptr<glitched::Instrument> instr;
    std::string engine_arg(argv[1]);
    std::string input_arg(argv[2]);
    std::string output_arg(argv[3]);
    std::string config_file = "glitched.toml";

    std::ifstream input_f(input_arg);

    std::ifstream cfs(config_file);
    toml::ParseResult pr = toml::parse(cfs);

    if (!pr.valid()) {
        std::cout << config_file << ": toml parse error: " << pr.errorReason << std::endl;
        return -2;
    }

    const toml::Value &v = pr.value;

    if (engine_arg == "salt") {
        auto oscs_config = v.find("osc")->as<std::vector<toml::Value>>();
        std::vector<glitched::Oscillator> voices;
        for (const auto osc_config : oscs_config) {
            glitched::Wave wave = parseWave(osc_config.get<std::string>("wave"));
            auto osc = glitched::Oscillator(wave);
            osc.tune = osc_config.get<int>("tune");
            osc.mix = osc_config.get<double_t>("mix");
            if (osc_config.find("transpose")) {
                osc.transpose = osc_config.get<int>("transpose");
            }
            voices.push_back(osc);
        }
        //        auto osc_pitchMod = std::make_shared<glitched::LFO>(4.0, 0.5);
        //        osc1.pitchMod = osc_pitchMod;
        //        osc2.pitchMod = osc_pitchMod;
        auto env_config = v.find("env");
        auto ampEnvVals = env_config->get<std::vector<double>>("amp");
        auto ampEnv = glitched::Envelope(ampEnvVals[0], ampEnvVals[1], ampEnvVals[2], ampEnvVals[3]);
        auto filter_config = v.find("filter");
//        auto cutoffMod = std::make_shared<glitched::LFO>(2.0);
        auto cutoff = glitched::Value(filter_config->get<double_t>("cutoff"), nullptr, 0.1);
        auto resonance = glitched::Value(filter_config->get<double_t>("resonance"));
        auto filter = glitched::Filter(glitched::FilterMode::LowPass, cutoff, resonance);
        auto salty = std::make_shared<glitched::SaltSynth>(voices, ampEnv, filter);
        instr = salty;
    } else if (engine_arg == "sand") {
        auto grain_config = v.find("grain");
        // load audio data for granular sampling
        auto grainSource = glitched::WaveHelper::read(grain_config->get<std::string>("source"));
        auto sandy = std::make_shared<glitched::SandSynth>();
        sandy->grind(grainSource);
        instr = sandy;
    } else if (engine_arg == "nasm") {
        // assembler for NoteASM
        std::cout << "assembling [" << input_arg << "]...";
        auto assembler = glitched::NasmAssembler(input_f);
        std::ofstream ouf(output_arg);
        assembler.assemble(ouf);
        std::cout << "done [" << output_arg << "]" << std::endl;
        return 0;
    }
    std::cout << "[g] synth engine: " << engine_arg << std::endl;
    std::cout << "[g] input file: " << input_arg << std::endl;
    std::cout << "[g] output file: " << output_arg << std::endl;

    glitched::NoteMachine noteMachine(INT16_MAX, *instr.get());
    noteMachine.loadProgram(demo_generate_scale());
    noteMachine.execute();

    glitched::WaveHelper::save(noteMachine.audioBuffer, output_arg);
}
