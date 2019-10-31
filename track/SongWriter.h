#pragma once

#include "../util/AudioFile.h"
#include "../util/StereoSample.h"
#include <string>
#include <vector>

namespace glitched {
class SongWriter {
    AudioFile<double> audioFile;

  public:
    explicit SongWriter(size_t size);

    void insert(size_t pos, glitched::StereoSample audioBuffer);

    bool save(std::string path);
};
} // namespace glitched
