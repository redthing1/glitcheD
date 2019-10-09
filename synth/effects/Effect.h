//
// Created by xdrie on 10/9/19.
//
#pragma once

namespace glitched {
    class Effect {
    public:
        virtual double value(double t) const { return 0; }
    };
}


