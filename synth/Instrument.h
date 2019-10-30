//
// Created by xdrie on 10/29/19.
//
#pragma once

#include <cstdint>
#include <vector>

class Instrument {
  public:
    virtual std::vector<double> play(uint16_t note, double dur, double vol) = 0;
};
