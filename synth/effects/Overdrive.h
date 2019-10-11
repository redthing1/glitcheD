//
// Created by xdrie on 10/9/19.
//
#pragma once

#include "../mod/Parameter.h"
#include "Effect.h"

namespace glitched {
class Overdrive : public Effect {
  public:
    const Parameter &gain;
    const Parameter &threshold;

    explicit Overdrive(const Parameter &gain, const Parameter &threshold);

    virtual double value(double v) const override;
};
} // namespace glitched
