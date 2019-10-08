
#include <cmath>
#include <iostream>
#include <memory>
#include <vector>

#include "constants.h"
#include "SongWriter.h"
#include "Oscillator.h"
#include "Tuning.h"

int main(int argc, const char *argv[]) {

    // source: http://thecodeinn.blogspot.com/2014/02/developing-digital-synthesizer-in-c_2.html
    auto osc1 = Oscillator(Wave::Sine);
    auto osc2 = Oscillator(Wave::Square);
    auto buf = osc1.play(noteFrequency(49), 1, 0.7f);
    auto buf_sinA = osc1.play(noteFrequency(49), 1, 0.3f);
    auto buf_sqrA = osc2.play(noteFrequency(49), 1, 0.3f);
    auto buf_sinC = osc1.play(noteFrequency(52), 1, 0.3f);
    auto buf_sinE = osc1.play(noteFrequency(56), 1, 0.3f);
    auto buf_sinG = osc1.play(noteFrequency(59), 1, 0.3f);

    uint32_t audioBufferSize = buf.size();
    std::cout << "buf size " << audioBufferSize << std::endl;

    // 8 notes
    SongWriter songWriter(4 * SAMPLE_RATE);
    songWriter.insert(0 * SAMPLE_RATE, buf_sqrA);
    songWriter.insert(1 * SAMPLE_RATE, buf_sinC);
    songWriter.insert(2 * SAMPLE_RATE, buf_sinE);
    songWriter.insert(3 * SAMPLE_RATE, buf_sinA);
    songWriter.insert(3 * SAMPLE_RATE, buf_sinC);
    songWriter.insert(3 * SAMPLE_RATE, buf_sinE);
    songWriter.save("out.wav");

    std::cout << "cmon" << std::endl;
}

