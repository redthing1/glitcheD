//
// Created by xdrie on 10/8/19.
//
#pragma once

#include <memory>

namespace glitched {
    class Parameter {
    public:
        explicit Parameter();
        virtual double value(double t) const;
    };

    class Value: public Parameter {
    public:
        double val;

        const std::shared_ptr<Parameter> mod;
        double modAmount;

        explicit Value(double value);
        explicit Value(double value, const std::shared_ptr<Parameter> mod);
        double value(double t) const override;
    };
}
