
#include "WaveHelper.h"

bool glitched::WaveHelper::save(glitched::StereoSample buffer, std::string path) {
    auto dest = AudioFile<double>();
    dest.setAudioBufferSize(NUM_CHANNELS, buffer.size());
    dest.setBitDepth(BIT_DEPTH);
    dest.setSampleRate(SAMPLE_RATE);
    AudioFile<double>::AudioBuffer audioBuffer;
    audioBuffer.resize(NUM_CHANNELS);
    audioBuffer[0].resize(buffer.size());
    audioBuffer[1].resize(buffer.size());
    // copy data
    for (size_t i = 0; i < buffer.size(); i++) {
        audioBuffer[0][i] = buffer.l[i];
        audioBuffer[1][i] = buffer.r[i];
    }
    dest.setAudioBuffer(audioBuffer);
    return dest.save(path, AudioFileFormat::Wave);
}

glitched::StereoSample glitched::WaveHelper::read(std::string path) {
    glitched::StereoSample samp;
    auto source = AudioFile<double>();
    source.load(path);
    // make sure source matches
    assert(source.getSampleRate() == SAMPLE_RATE);
    assert(source.getBitDepth() == BIT_DEPTH);
    assert(source.getNumChannels() == NUM_CHANNELS);

    // copy to internal sample representation
    auto sampleCount = source.getNumSamplesPerChannel();
    samp.resize(sampleCount);
    for (int i = 0; i < sampleCount; i++) {
        samp.l[i] = source.samples[0][i];
        samp.r[i] = source.samples[1][i];
    }

    return samp;
}
