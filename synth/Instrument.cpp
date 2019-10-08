#include "Instrument.h"

#include <utility>
#include "../constants.h"
#include "../util/Tuning.h"

glitched::Instrument::Instrument(std::vector<Oscillator> voices, Envelope amplitudeEnvelope) : voices(std::move(voices)), amplitudeEnvelope(amplitudeEnvelope) {

}

std::vector<double> glitched::Instrument::play(uint16_t note, double dur, double vol) {
    auto buf = std::vector<double>();
    buf.resize(dur * SAMPLE_RATE);
    for (int i = 0; i < voices.size(); i++) {
        auto voiceBuf = voices[i].play(glitched::note(note), dur, vol / voices.size());
        for (int j = 0; j < buf.size(); j++) {
            buf[j] += voiceBuf[j];
        }
    }
    return buf;
}
