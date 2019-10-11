//
// Created by xdrie on 10/9/19.
//
#pragma once

namespace glitched {
class Effect {
  public:
    bool enabled = true;
    virtual double value(double t) const { return 0; }
};
} // namespace glitched
