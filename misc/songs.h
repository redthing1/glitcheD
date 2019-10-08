#pragma once

#include <vector>
#include <cstdint>
#include "../track/NoteMachine.h"

static const std::vector<uint8_t> demo_testSong1 = {
        glitched::NoteMachine::VEL, 96,
        glitched::NoteMachine::DUR, 24,
        glitched::NoteMachine::BPS, 48,

        glitched::NoteMachine::PLAY, 49,

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
        glitched::NoteMachine::BPS, 96,

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