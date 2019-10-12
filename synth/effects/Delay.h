//
// Created by xdrie on 10/11/19.
//
#pragma once

#include "../mod/Parameter.h"
#include "Effect.h"
#include <memory>
#include <vector>
namespace glitched {

class Delay : public Effect {
  public:
    Knob time;
    Knob gain;

    std::vector<double> buffer;

    explicit Delay(Knob time, Knob gain);

    virtual double value(double v, double t) override;
};
} // namespace glitched
