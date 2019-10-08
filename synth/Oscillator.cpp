#include <cmath>
#include "Oscillator.h"
#include "../constants.h"

inline std::vector<double> makeBuffer(size_t sampleCount) {
    // The amount of samples the buffer must hold
    auto buffer = std::vector<double>(); // create a new array with size for the entire buffer
    buffer.resize(sampleCount);
    return buffer;
}

std::vector<double> glitched::Oscillator::genSin(double freq, double dur, double amp, double phase) {
    // The phase increment is the phase value the wave increases per sample
    double delta = (tau * freq) / SAMPLE_RATE;

    size_t sampleCount = SAMPLE_RATE * dur;
    auto buffer = makeBuffer(sampleCount);
    int a = buffer.size();

    for (int i = 0; i < sampleCount; i++) // fill the buffer
    {
        buffer[i] = std::sin(phase) * amp;
        phase += delta;

        // when the wave hits 2Pi/360˚/full circle we have to reset the phase
        if (phase >= tau) phase -= tau;
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
        for (int j = 0; j < sampleCount; j++) {
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
        for (int j = 0; j < sampleCount; j++) {
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
        for (int j = 0; j < sampleCount; j++) {
            buf[j] += partial[j];
        }
    }

    return buf;
}

glitched::Oscillator::Oscillator(Wave wave) : wave(wave) { }

std::vector<double> glitched::Oscillator::play(double freq, double dur, double amp) {
    switch (wave) {
        case Wave::Sine:
            return genSin(freq, dur, amp);
        case Wave::Square:
            return genSqr(freq, dur, amp);
        case Wave::Saw:
            return genSaw(freq, dur, amp);
        case Wave::Triangle:
            return genTri(freq, dur, amp);
    }
}


