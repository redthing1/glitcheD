#pragma once

#include "../synth/SaltSynth.h"
#include "../util/StereoSample.h"
#include <cstdint>
#include <vector>

namespace glitched {
class NoteMachine {
    using byte = uint8_t;

    std::vector<byte> memory;
    int programCounter;
    int stackPointer;

    byte noteDuration = 24;
    byte noteBps = 48;
    byte noteVelocity = 128;

    byte noteMode = MODE_IMMEDIATE;

    uint32_t bufferPosition;

    const byte MODE_IMMEDIATE = 0x00;
    const byte MODE_COMPOSE = 0x01;

    const byte FRAME_DELIMITER = 0x00;

    double getDuration();
    double getVelocity();
    void copyAudio(StereoSample buffer, uint32_t position);

  public:
    Instrument &instrument;
    StereoSample audioBuffer;

    enum Instruction : byte {
        NOP = 0x00, // nop
        MODE = 0x01, // set mode
        PLAY = 0x10, // play note
        PUSH = 0x11, // push to note stack
        FRAME = 0x12, // start note stack
        BATCH = 0x13, // play note stack
        REST = 0x14, // seek forward
        BACK = 0x15, // seek back
        DUR = 0x20, // set _dur
        VEL = 0x21, // set _vel
        BPS = 0x22, // set _bps
        RET = 0x99, // ret
    };

    explicit NoteMachine(uint16_t memorySize, Instrument &instrument);
    void loadProgram(std::vector<byte> program);
    void execute();
};
} // namespace glitched