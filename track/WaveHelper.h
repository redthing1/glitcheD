#pragma once

#include "../util/AudioFile.h"
#include "../util/StereoSample.h"
#include <string>
#include <vector>

namespace glitched {
class WaveHelper {
    static const int NUM_CHANNELS = 2;

  public:
    static bool save(glitched::StereoSample buffer, std::string path);
    static StereoSample read(std::string path);
};
} // namespace glitched
