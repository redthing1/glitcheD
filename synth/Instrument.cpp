#include "Instrument.h"

#include <utility>
#include "../constants.h"
#include "../util/Tuning.h"

glitched::Instrument::Instrument(std::vector<Oscillator> voices, Envelope amplitudeEnvelope, Filter filter) : voices(
        std::move(voices)), amplitudeEnvelope(amplitudeEnvelope),
        filter(filter) {
}

std::vector<double> glitched::Instrument::play(uint16_t note, double dur, double vol) {
    auto buf = std::vector<double>();
//    buf.resize(dur * SAMPLE_RATE);
    auto sampleLength = dur * SAMPLE_RATE;
    buf.resize(sampleLength * 2); // dirty hack for release
    for (int i = 0; i < voices.size(); i++) {
        auto oscBuf = voices[i].play(glitched::note(note), dur, vol / voices.size());
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
    return buf;
}
