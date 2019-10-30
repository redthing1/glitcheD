//
// Created by xdrie on 10/11/19.
//
#include "Delay.h"
#include "../../defs.h"
#include <utility>

glitched::Delay::Delay(glitched::Knob time, glitched::Knob gain) : time(std::move(time)), gain(std::move(gain)) {
    auto buf_size = 2 * this->time->value(0) * SAMPLE_RATE;
    buffer.resize(buf_size);
}

double glitched::Delay::value(double v, double t) {
    auto samp = t * SAMPLE_RATE;
    auto delTime = time->value(t);
    if (delTime * SAMPLE_RATE > static_cast<double>(buffer.size() / 2)) {
        buffer.resize(2 * delTime * SAMPLE_RATE);
    }
    auto out = v;
    if (t > delTime) {
        auto delSamp = delTime * SAMPLE_RATE;
        auto f = buffer[samp - delSamp] * gain->value(t);
        out = (v + f) / 2;
    }
    buffer[static_cast<long>(samp)] = v;
    return out;
}
