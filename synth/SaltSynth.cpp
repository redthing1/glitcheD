#include "SaltSynth.h"

#include "../constants.h"
#include "../util/Tuning.h"
#include <utility>

glitched::SaltSynth::SaltSynth(std::vector<Oscillator> voices, Envelope amplitudeEnvelope, Filter filter)
    : voices(std::move(voices)), amplitudeEnvelope(std::move(amplitudeEnvelope)), filter(filter) {

}

std::vector<double> glitched::SaltSynth::play(uint16_t note, double dur, double vol) {
    auto buf = std::vector<double>();
    //    buf.resize(dur * SAMPLE_RATE);
    auto sampleLength = dur * SAMPLE_RATE;
    buf.resize(sampleLength * 2); // dirty hack for release
    for (auto &voice : voices) {
        auto freq = glitched::note(note);
        auto oscBuf = voice.play(freq, dur, vol / voices.size());
        for (int j = 0; j < sampleLength; j++) {
            double t = static_cast<double>(j) / SAMPLE_RATE;
            auto envVal = amplitudeEnvelope.calc(true, static_cast<double>(j) / SAMPLE_RATE);
            auto val = oscBuf[j] * envVal * glitched::MIX_NOTE;
            val = filter.process(val, t);
            buf[j] += val;
        }
        for (int j = 0; j < sampleLength; j++) {
            double t = static_cast<double>(j) / SAMPLE_RATE;
            auto envVal = amplitudeEnvelope.calc(false, static_cast<double>(j) / SAMPLE_RATE);
            auto val = oscBuf[j] * envVal * glitched::MIX_RELEASE;
            val = filter.process(val, t);
            buf[sampleLength + j] += val;
        }
    }
    for (auto &effect : effects) {
        if (!effect.get().enabled)
            continue;
        for (int j = 0; j < sampleLength; j++) {
            auto t = static_cast<double>(j) / SAMPLE_RATE;
            auto out = effect.get().value(buf[j], t);
            buf[j] = out;
        }
    }
    return buf;
}
