//
// Created by xdrie on 10/8/19.
//
#pragma once

namespace glitched {
    class Parameter {
    public:
        virtual double value(double t) = 0;
    };
}
