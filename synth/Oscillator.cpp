#include "Oscillator.h"
#include "../constants.h"
#include "../util/Tuning.h"
#include <cmath>
#include <stdexcept>

inline std::vector<double> makeBuffer(size_t sampleCount) {
    // The amount of samples the buffer must hold
    auto buffer = std::vector<double>(); // create a new array with size for the entire buffer
    buffer.resize(sampleCount);
    return buffer;
}

std::vector<double> glitched::Oscillator::genSin(double freq, double dur, double amp, double phase) {
    size_t sampleCount = SAMPLE_RATE * dur;
    auto buffer = makeBuffer(sampleCount);
    auto cFreq = freq;

    for (size_t i = 0; i < sampleCount; i++) { // fill the buffer
        buffer[i] = std::sin(phase) * amp;
        // apply pitch mod
        double t = static_cast<double>(i) / SAMPLE_RATE;
        if (pitchMod) {
            cFreq = glitched::detune(freq, static_cast<int>(pitchMod->value(t) * 100));
        }
        phase += (tau * cFreq) / SAMPLE_RATE;
    }

    return buffer;
}

std::vector<double> glitched::Oscillator::genSqr(double freq, double dur, double amp) {
    size_t sampleCount = SAMPLE_RATE * dur;
    auto buf = makeBuffer(sampleCount);
    // square wave is odd partials
    for (int i = 1; i <= PARTIALS; i += 2) {
        auto partial = genSin(freq * i, dur, amp / i);
        // add the partial
        for (size_t j = 0; j < sampleCount; j++) {
            buf[j] += partial[j];
        }
    }

    return buf;
}

std::vector<double> glitched::Oscillator::genSaw(double freq, double dur, double amp, double factor) {
    size_t sampleCount = SAMPLE_RATE * dur;
    auto buf = makeBuffer(sampleCount);
    // saw wave is all partials
    for (int i = 1; i <= PARTIALS; i += 1) {
        auto partial = genSin(freq * i, dur, (amp * factor) / i);
        // add the partial
        for (size_t j = 0; j < sampleCount; j++) {
            buf[j] += partial[j];
        }
    }

    return buf;
}

std::vector<double> glitched::Oscillator::genTri(double freq, double dur, double amp) {
    size_t sampleCount = SAMPLE_RATE * dur;
    auto buf = makeBuffer(sampleCount);
    int sign = 1;
    for (int i = 1; i <= PARTIALS; i += 2) {
        auto partial = genSin(freq * i, dur, (sign * amp) / (i * i));
        sign = -sign;
        // add the partial
        for (size_t j = 0; j < sampleCount; j++) {
            buf[j] += partial[j];
        }
    }

    return buf;
}

inline double randf() { return ((double)std::rand() / (RAND_MAX)); }

std::vector<double> glitched::Oscillator::genNoise(double dur, double amp) {
    size_t sampleCount = SAMPLE_RATE * dur;
    auto buf = makeBuffer(sampleCount);
    for (size_t j = 0; j < sampleCount; j++) {
        buf[j] = ((randf() * 2) - 1) * amp;
    }

    return buf;
}

glitched::Oscillator::Oscillator(Wave wave) : wave(wave), tune(0), transpose(0), mix(1) {}

std::vector<double> glitched::Oscillator::play(double freq, double dur, double amp) {
    // apply tune to freq
    freq = glitched::detune(freq, transpose * 100);
    freq = glitched::detune(freq, tune);
    amp = amp * mix;

    switch (wave) {
    case Wave::Sine:
        return genSin(freq, dur, amp);
    case Wave::Square:
        return genSqr(freq, dur, amp);
    case Wave::Saw:
        return genSaw(freq, dur, amp);
    case Wave::Triangle:
        return genTri(freq, dur, amp);
    case Wave::Noise:
        return genNoise(dur, amp);
    }
    throw std::invalid_argument("invalid waveform");
}
