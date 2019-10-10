//
// Created by xdrie on 10/8/19.
//
#include "Parameter.h"

glitched::Parameter::Parameter() = default;

glitched::Value::Value(double value) : Value(value, std::make_shared<Parameter>()) {
}

glitched::Value::Value(double value, const std::shared_ptr<Parameter> mod) : val(value), mod(mod), modAmount(0.0) {
}

double glitched::Value::value(double t) const {
    if (modAmount < std::numeric_limits<double>::epsilon()) {
        return val;
    }
    // calculate mod
    auto mVal = mod->value(t) * modAmount;
    return val + mVal;
}

double glitched::Parameter::value(double t) const {
    return 0;
}
