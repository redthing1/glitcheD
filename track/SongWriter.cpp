
#include "SongWriter.h"

glitched::SongWriter::SongWriter(size_t size) : audioFile(AudioFile<double>()) {
    const int numChannels = 2; // stereo audio
    audioFile.setAudioBufferSize(numChannels, size);
    audioFile.setBitDepth(BIT_DEPTH);
    audioFile.setSampleRate(SAMPLE_RATE);
    AudioFile<double>::AudioBuffer audioBuffer;
    audioBuffer.resize(numChannels);
    audioBuffer[0].resize(size);
    audioBuffer[0].resize(size);
    audioFile.setAudioBuffer(audioBuffer);
}

bool glitched::SongWriter::save(std::string path) { return audioFile.save(path, AudioFileFormat::Wave); }

void glitched::SongWriter::insert(size_t pos, glitched::StereoSample audioBuffer) {
    for (size_t i = 0; i < audioBuffer.size(); i++) {
        audioFile.samples[0][pos + i] += audioBuffer.l[i];
        audioFile.samples[1][pos + i] += audioBuffer.r[i];
    }
}
