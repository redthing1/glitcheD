#pragma once

#include "../util/AudioFile.h"
#include <string>
#include <vector>

namespace glitched {
class SongWriter {
    AudioFile<double> audioFile;

  public:
    explicit SongWriter(size_t size);

    void insert(size_t pos, std::vector<double> buf);

    bool save(std::string path);
};
} // namespace glitched
