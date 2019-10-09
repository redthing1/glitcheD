//
// Created by xdrie on 10/8/19.
//

#pragma once

namespace glitched {
    enum FilterMode {
        LowPass,
        HighPass,
        BandPass
    };

    class Filter {
        double feedback;
        double buf0, buf1;

        inline void calculateFeedback();
    public:
        FilterMode mode;
        double cutoff;
        double resonance;

        explicit Filter(FilterMode mode, double cutoff, double resonance);
        double process(double input);
    };
}