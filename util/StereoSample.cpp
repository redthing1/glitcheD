//
// Created by xdrie on 10/30/19.
//
#include "StereoSample.h"
void glitched::StereoSample::resize(size_t size) {
    l.resize(size);
    r.resize(size);
}
void glitched::StereoSample::copy(glitched::StereoSample &source, glitched::StereoSample &dest, uint32_t position) {
    for (size_t i = 0; i < source.l.size(); i++) {
        dest.l[position + i] = source.l[i];
    }
    for (size_t i = 0; i < source.r.size(); i++) {
        dest.r[position + i] = source.r[i];
    }
}
glitched::StereoSample glitched::StereoSample::fromMono(glitched::Sample monoSample) {
    StereoSample sample;
    sample.l = monoSample;
    sample.r = monoSample;
    return sample;
}
