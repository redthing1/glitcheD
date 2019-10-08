#pragma once

#include <vector>

static const int PARTIALS = 64;

std::vector<double> genSin(double freq, double dur, double amp = 1.0, double phase = 0);
std::vector<double> genSqr(double freq, double dur, double amp = 1.0);
std::vector<double> genSaw(double freq, double dur, double amp = 1.0, double factor = 1.0);
std::vector<double> genTri(double freq, double dur, double amp = 1.0);