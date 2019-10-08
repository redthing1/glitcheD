#pragma once

#include <string>
#include <vector>
#include "AudioFile.h"

class SongWriter {
    AudioFile<double> audioFile;

public:
    explicit SongWriter(size_t size);
    void insert(size_t pos, std::vector<double> buf);
    bool save(std::string path);
};
