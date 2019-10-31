#pragma once

#include "../track/NoteMachine.h"
#include <cstdint>
#include <vector>

// clang-format off

static const std::vector<uint8_t> demo_basic = {
    glitched::NoteMachine::VEL, 96,
    glitched::NoteMachine::DUR, 24,
    glitched::NoteMachine::BPS, 48,

    glitched::NoteMachine::DUR, 16,
    glitched::NoteMachine::PLAY, 49, // A
    glitched::NoteMachine::PLAY, 51,
    glitched::NoteMachine::PLAY, 53,
    glitched::NoteMachine::PLAY, 54,
    glitched::NoteMachine::PLAY, 56,
    glitched::NoteMachine::PLAY, 58,
    glitched::NoteMachine::PLAY, 60,
    glitched::NoteMachine::PLAY, 61, // A
    glitched::NoteMachine::PLAY, 63,
    glitched::NoteMachine::PLAY, 65,
    glitched::NoteMachine::PLAY, 66,
    glitched::NoteMachine::PLAY, 68,
    glitched::NoteMachine::PLAY, 70,
    glitched::NoteMachine::PLAY, 72,
    glitched::NoteMachine::PLAY, 73, // A
    glitched::NoteMachine::PLAY, 75,
    glitched::NoteMachine::PLAY, 77,
    glitched::NoteMachine::PLAY, 78,
    glitched::NoteMachine::PLAY, 80,
    glitched::NoteMachine::PLAY, 82,
    glitched::NoteMachine::PLAY, 84,
    glitched::NoteMachine::PLAY, 85, // A

    glitched::NoteMachine::RET,
};

static const std::vector<uint8_t> demo_testSong1 = {
        glitched::NoteMachine::VEL, 96,
        glitched::NoteMachine::DUR, 24,
        glitched::NoteMachine::BPS, 48,

        glitched::NoteMachine::DUR, 24,
        glitched::NoteMachine::PLAY, 49,

        glitched::NoteMachine::DUR, 24,
        glitched::NoteMachine::REST,

        glitched::NoteMachine::DUR, 72,
        glitched::NoteMachine::VEL, 32,
        glitched::NoteMachine::FRAME,
        glitched::NoteMachine::PUSH, 49,
        glitched::NoteMachine::PUSH, 52,
        glitched::NoteMachine::PUSH, 56,
        glitched::NoteMachine::BATCH,

        glitched::NoteMachine::RET,
};

static const std::vector<uint8_t> demo_stardustCrusaders = {
        glitched::NoteMachine::VEL, 96,
        glitched::NoteMachine::DUR, 24,
        glitched::NoteMachine::BPS, 48,

        // -- jotaro's theme
        glitched::NoteMachine::DUR, 36,
        glitched::NoteMachine::PLAY, 45, // F4

        glitched::NoteMachine::DUR, 24,
        glitched::NoteMachine::PLAY, 43,

        glitched::NoteMachine::DUR, 12,
        glitched::NoteMachine::PLAY, 40,

        glitched::NoteMachine::DUR, 24,
        glitched::NoteMachine::PLAY, 38,

        glitched::NoteMachine::DUR, 36,
        glitched::NoteMachine::PLAY, 33, // F3

        glitched::NoteMachine::DUR, 24,
        glitched::NoteMachine::PLAY, 39,

        glitched::NoteMachine::DUR, 12,
        glitched::NoteMachine::PLAY, 38,

        glitched::NoteMachine::DUR, 24,
        glitched::NoteMachine::PLAY, 36,

        glitched::NoteMachine::DUR, 36,
        glitched::NoteMachine::PLAY, 33, // F3

        glitched::NoteMachine::DUR, 24,
        glitched::NoteMachine::PLAY, 39,

        glitched::NoteMachine::DUR, 12,
        glitched::NoteMachine::PLAY, 38,

        glitched::NoteMachine::DUR, 24,
        glitched::NoteMachine::PLAY, 36,

        glitched::NoteMachine::DUR, 36,
        glitched::NoteMachine::PLAY, 33, // F3

        glitched::NoteMachine::DUR, 24,
        glitched::NoteMachine::PLAY, 42,

        glitched::NoteMachine::DUR, 12,
        glitched::NoteMachine::PLAY, 43,

        glitched::NoteMachine::DUR, 24,
        glitched::NoteMachine::PLAY, 44,

        glitched::NoteMachine::DUR, 36,
        glitched::NoteMachine::PLAY, 45, // F4

        glitched::NoteMachine::DUR, 24,
        glitched::NoteMachine::PLAY, 43,

        glitched::NoteMachine::DUR, 12,
        glitched::NoteMachine::PLAY, 40,

        glitched::NoteMachine::DUR, 24,
        glitched::NoteMachine::PLAY, 38,

        glitched::NoteMachine::DUR, 36,
        glitched::NoteMachine::PLAY, 33, // F3

        glitched::NoteMachine::DUR, 24,
        glitched::NoteMachine::PLAY, 39,

        glitched::NoteMachine::DUR, 12,
        glitched::NoteMachine::PLAY, 38,

        glitched::NoteMachine::DUR, 24,
        glitched::NoteMachine::PLAY, 36,

        glitched::NoteMachine::DUR, 36,
        glitched::NoteMachine::PLAY, 33, // F3

        glitched::NoteMachine::DUR, 24,
        glitched::NoteMachine::PLAY, 39,

        glitched::NoteMachine::DUR, 12,
        glitched::NoteMachine::PLAY, 38,

        glitched::NoteMachine::DUR, 24,
        glitched::NoteMachine::PLAY, 36,

        glitched::NoteMachine::DUR, 36,
        glitched::NoteMachine::PLAY, 33, // F3

        glitched::NoteMachine::DUR, 24,
        glitched::NoteMachine::PLAY, 42,

        glitched::NoteMachine::DUR, 12,
        glitched::NoteMachine::PLAY, 43,

        glitched::NoteMachine::DUR, 24,
        glitched::NoteMachine::PLAY, 44,

        glitched::NoteMachine::DUR, 36,
        glitched::NoteMachine::PLAY, 45, // F4
        // -- end

        glitched::NoteMachine::RET,
};
