
#include <cmath>
#include <iostream>
#include <memory>
#include <vector>

#include "constants.h"
#include "SongWriter.h"
#include "Oscillator.h"

int main(int argc, const char *argv[]) {

    // source: http://thecodeinn.blogspot.com/2014/02/developing-digital-synthesizer-in-c_2.html
    auto buf = genSin(440, 1, 0.7f);
    auto buf_sinA = genSin(440, 1, 0.3f);
    auto buf_sqrA = genSqr(440, 1, 0.3f);
    auto buf_sawA = genSaw(440, 1, 0.3f);
    auto buf_triA = genTri(440, 1, 0.3f);
    auto buf_sinC = genSin(523.2511, 1, 0.3f);
    auto buf_sinE = genSin(659.2551, 1, 0.3f);
    auto buf_sinG = genSin(783.9909, 1, 0.3f);

    uint32_t audioBufferSize = buf.size();
    std::cout << "buf size " << audioBufferSize << std::endl;

    // 8 notes
    SongWriter songWriter(4 * SAMPLE_RATE);
    songWriter.insert(0 * SAMPLE_RATE, buf_triA);
    songWriter.insert(1 * SAMPLE_RATE, buf_sinC);
    songWriter.insert(2 * SAMPLE_RATE, buf_sinE);
    songWriter.insert(3 * SAMPLE_RATE, buf_sinA);
    songWriter.insert(3 * SAMPLE_RATE, buf_sinC);
    songWriter.insert(3 * SAMPLE_RATE, buf_sinE);
    songWriter.save("out.wav");

    std::cout << "cmon" << std::endl;
}

