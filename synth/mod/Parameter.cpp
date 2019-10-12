//
// Created by xdrie on 10/8/19.
//
#include "Parameter.h"

#include <utility>

glitched::Parameter::Parameter() = default;

glitched::Value::Value(double value) : Value(value, std::make_shared<Parameter>(), 0) {}

glitched::Value::Value(double value, std::shared_ptr<Parameter> mod, double modAmount) : val(value), mod(std::move(mod)), modAmount(modAmount) {}

double glitched::Value::value(double t) const {
    if (!mod || modAmount < std::numeric_limits<double>::epsilon()) {
        return val;
    }
    // calculate mod
    auto mVal = mod->value(t) * modAmount;
    return val + mVal;
}

double glitched::Parameter::value(double t) const { return 0; }
