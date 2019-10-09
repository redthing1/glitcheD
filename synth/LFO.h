//
// Created by xdrie on 10/8/19.
//
#pragma once


#include "Parameter.h"

namespace glitched {
    class LFO : public Parameter {
    public:
        double freq;
        double amplitude;

        explicit LFO(double freq, double amplitude);
        double value(double t) override;
    };
}
