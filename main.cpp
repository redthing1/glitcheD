
#include <cmath>
#include <memory>

#include "constants.h"

// Using standard typedefs for portability, you can change them to normal data types if you like

// @param dur: I was indecisive about whether the duration
// should be 32 or 16 bits aka 130 years or 18 hours, but then
// again you never know what sound installations people come up with

std::unique_ptr<uint16_t[]> gen(float freq, uint32_t dur, float vol = 1.0);

int main(int argc, const char *argv[]) {

    // source: http://thecodeinn.blogspot.com/2014/02/developing-digital-synthesizer-in-c_2.html
    std::unique_ptr<uint16_t[]> buf = gen(440, 3);
}

std::unique_ptr<uint16_t[]> gen(float freq, uint32_t dur, float vol) {
    uint32_t sampleRate = 44100; // samples per second

    // initial phase position
    double phase = 0;

    // The phase increment is the phase value the wave increases per sample
    double phaseIncrement = (tau * freq) / sampleRate;

    // The amount of samples the buffer must hold
    size_t sampleCount = sampleRate * dur;

    auto buffer = std::make_unique<uint16_t[]>(sampleCount); // create a new array with size for the entire buffer

    for (int i = 0; i < sampleCount; i++) // fill the buffer
    {
        // the factor 32767 comes from the fact that .wav files store samples
        // as 16 bit signed integers, before this the values are normalized
        // between -1 and + 1 (the sine values).
        buffer[i] = 32767 * (std::sin(phase) * vol);
        phase += phaseIncrement;

        // when the wave hits 2Pi/360˚/full circle we have to reset the phase
        if (phase >= tau) phase -= tau;
    }

    return buffer;
}
