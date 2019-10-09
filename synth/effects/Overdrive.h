//
// Created by xdrie on 10/9/19.
//
#pragma once

#include "Effect.h"
#include "../mod/Parameter.h"

namespace glitched {
    class Overdrive : public Effect {
    public:
        const Parameter &gain;
        const Parameter &threshold;

        explicit Overdrive(const Parameter &gain, const Parameter &threshold);

        virtual double value(double v) const override;
    };
}
