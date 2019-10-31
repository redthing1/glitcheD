//
// Created by xdrie on 10/9/19.
//
#pragma once

namespace glitched {
class Effect {
  public:
    bool enabled = true;

    virtual double value(double v, double t) = 0;
    virtual void reset() {}
};
} // namespace glitched
