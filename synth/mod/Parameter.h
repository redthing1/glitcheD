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

class Value : public Parameter {
  public:
    double val;

    std::shared_ptr<Parameter> mod;
    double modAmount;

    explicit Value(double value);
    explicit Value(double value, std::shared_ptr<Parameter> mod, double modAmount);
    double value(double t) const override;
};
} // namespace glitched
