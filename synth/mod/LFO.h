//
// Created by xdrie on 10/8/19.
//
#pragma once

#include "Parameter.h"

namespace glitched {
class LFO : public Parameter {
  public:
    double freq;

    explicit LFO(double freq);
    double value(double t) const override;
};
} // namespace glitched
