//
// Created by xdrie on 10/9/19.
//
#pragma once

#include "../mod/Parameter.h"
#include "Effect.h"

namespace glitched {
class Overdrive : public Effect {
  public:
    std::shared_ptr<Parameter> gain;
    std::shared_ptr<Parameter> threshold;

    explicit Overdrive(std::shared_ptr<Parameter> gain, std::shared_ptr<Parameter> threshold);

    virtual double value(double v) const override;
};
} // namespace glitched
