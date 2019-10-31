//
// Created by xdrie on 10/30/19.
//
#pragma once

#include "../defs.h"
namespace glitched{
class StereoSample {
  public:
    Sample l;
    Sample r;
    void resize(size_t size);
    static StereoSample fromMono(Sample monoSample);
    static void copy(StereoSample& source, StereoSample& dest, uint32_t position);
};
}
