
#include <cmath>
#include <stdint.h>

#define twoPI 6.28318530717958 // 2*pi = 360˚ = one full cycle

// Using standard typedefs for portability, you can change them to normal data types if you like

// @param dur: I was indecisive about whether the duration
// should be 32 or 16 bits aka 130 years or 18 hours, but then
// again you never know what sound installations people come up with

int16_t *gen(float freq, uint32_t dur, float vol = 1.0);

int main(int argc, const char *argv[]) {

    // source: http://thecodeinn.blogspot.com/2014/02/developing-digital-synthesizer-in-c_2.html
    int16_t *buff = gen(440, 3);

    /* Do something with it */

    delete[] buff;
}

int16_t *gen(float freq, uint32_t dur, float vol) {
    uint32_t samplerate = 44100;    // samples per second

    // initial phase, you could offset it, but then again you could not
    double phase = 0;

    // The phase increment is the phase value the phasor increases by
    // per sample.
    double phaseincr = twoPI / samplerate * freq;

    // The amount of samples the buffer must hold
    uint32_t total_samples = samplerate * dur;

    int16_t *buffer = new int16_t[total_samples]; // grab a new array with size for the entire buffer

    for (int i = 0; i < total_samples; i++) // fill the buffer
    {
        // the factor 32767 comes from the fact that .wav files store samples
        // as 16 bit signed integers, before this the values are normalized
        // between -1 and + 1 (the sine values). If you want to do something
        // else with these values before storing them somewhere I recommend leaving        // the factor away.
        buffer[i] = 32767 * (sin(phase) * vol);
        phase += phaseincr;

        // when the phasor hits 2Pi/360˚/full circle we have to reset the phase
        if (phase >= twoPI) phase -= twoPI;
    }

    return buffer;
}
