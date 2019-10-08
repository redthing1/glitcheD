
#include "SongWriter.h"
#include "constants.h"

SongWriter::SongWriter(size_t size) : audioFile(AudioFile<double>()) {
    const int numChannels = 1;
    audioFile.setAudioBufferSize(numChannels, size);
    audioFile.setBitDepth(BIT_DEPTH);
    audioFile.setSampleRate(SAMPLE_RATE);
    AudioFile<double>::AudioBuffer audioBuffer;
    audioBuffer.resize(numChannels);
    audioBuffer[0].resize(size);
    audioFile.setAudioBuffer(audioBuffer);
}

bool SongWriter::save(std::string path) {
    return audioFile.save(path, AudioFileFormat::Wave);
}

void SongWriter::insert(size_t pos, std::vector<double> buf) {
    for (int i = 0; i < buf.size(); i++) {
        audioFile.samples[0][pos + i] += buf[i];
    }
}
