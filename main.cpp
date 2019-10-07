
#include <cmath>
#include <memory>

#include "constants.h"
#include "AudioFile.h"

// Using standard typedefs for portability, you can change them to normal data types if you like

// @param dur: I was indecisive about whether the duration
// should be 32 or 16 bits aka 130 years or 18 hours, but then
// again you never know what sound installations people come up with

std::vector<double> gen(float freq, uint32_t dur, float vol = 1.0);

int main(int argc, const char *argv[]) {

    // source: http://thecodeinn.blogspot.com/2014/02/developing-digital-synthesizer-in-c_2.html
    auto buf = gen(440, 1, 0.7f);
    auto bufA = gen(440, 1, 0.3f);
    auto bufC = gen(523.2511, 1, 0.3f);
    auto bufE = gen(659.2551, 1, 0.3f);
    auto bufG = gen(783.9909, 1, 0.3f);

    uint32_t audioBufferSize = buf.size();
    std::cout << "buf size " << audioBufferSize << std::endl;

    AudioFile<double> outAudio;
    outAudio.setAudioBufferSize (1, audioBufferSize);
    outAudio.setBitDepth (24);
    outAudio.setSampleRate (44100);

    AudioFile<double>::AudioBuffer audioBuffer;
    audioBuffer.resize(1);
    audioBuffer[0].resize(audioBufferSize * 2);

    for (int i = 0; i < audioBufferSize; i++) {
        audioBuffer[0][i] = bufA[i] + bufC[i] + bufE[i];
    }
    for (int i = 0; i < audioBufferSize; i++) {
        audioBuffer[0][audioBufferSize + i] = bufC[i] + bufE[i] + bufG[i];
    }
    outAudio.setAudioBuffer(audioBuffer);

    outAudio.save("out.wav", AudioFileFormat::Wave);
    std::cout << "cmon" << std::endl;
}

std::vector<double> gen(float freq, uint32_t dur, float vol) {
    uint32_t sampleRate = 44100; // samples per second

    // initial phase position
    double phase = 0;

    // The phase increment is the phase value the wave increases per sample
    double phaseIncrement = (tau * freq) / sampleRate;

    // The amount of samples the buffer must hold
    size_t sampleCount = sampleRate * dur;

    auto buffer = std::vector<double>(sampleCount); // create a new array with size for the entire buffer

    for (int i = 0; i < sampleCount; i++) // fill the buffer
    {
        buffer[i] = std::sin(phase) * vol;
        phase += phaseIncrement;

        // when the wave hits 2Pi/360˚/full circle we have to reset the phase
        if (phase >= tau) phase -= tau;
    }

    return buffer;
}
