#include "NoteMachine.h"
#include "../defs.h"

glitched::NoteMachine::NoteMachine(uint16_t memorySize, SaltSynth &instrument, double duration)
    : programCounter(0), bufferPosition(0), instrument(instrument) {
    this->memory.resize(memorySize);
    stackPointer = memorySize - 1;
    audioBuffer.resize(duration * SAMPLE_RATE);
}

void glitched::NoteMachine::loadProgram(std::vector<uint8_t> program) {
    int a = this->memory.size();
    for (int i = 0; i < program.size(); i++) {
        this->memory[i] = program[i];
    }
}

void glitched::NoteMachine::execute() {
    bool running = true;
    while (running) {
        auto instr = static_cast<Instruction>(this->memory[programCounter]);

        switch (instr) {
        case NOP: {
            break;
        }
        case MODE: {
            byte mode = this->memory[programCounter++ + 1];
            noteMode = mode;
            break;
        }
        case PLAY: {
            byte note = this->memory[programCounter++ + 1];
            auto dur = getDuration(noteDuration);
            auto noteAudioBuffer = instrument.play(note, dur, getVelocity(noteVelocity));
            copyAudio(noteAudioBuffer, bufferPosition);
            bufferPosition += dur * SAMPLE_RATE;
            break;
        }
        case REST: {
            auto dur = getDuration(noteDuration);
            bufferPosition += dur * SAMPLE_RATE;
            break;
        }
        case BACK: {
            auto dur = getDuration(noteDuration);
            bufferPosition -= dur * SAMPLE_RATE;
            break;
        }
        case PUSH: {
            byte note = this->memory[programCounter++ + 1];
            this->memory[stackPointer--] = note;
            break;
        }
        case FRAME: {
            this->memory[stackPointer--] = FRAME_DELIMITER;
            break;
        }
        case BATCH: {
            auto dur = getDuration(noteDuration);
            while (this->memory[++stackPointer] != FRAME_DELIMITER) {
                byte note = this->memory[stackPointer];
                auto noteAudioBuffer = instrument.play(note, dur, getVelocity(noteVelocity));
                copyAudio(noteAudioBuffer, bufferPosition);
            }
            bufferPosition += dur * SAMPLE_RATE;
            break;
        }
        case DUR: {
            noteDuration = this->memory[programCounter++ + 1];
            break;
        }
        case VEL: {
            noteVelocity = this->memory[programCounter++ + 1];
            break;
        }
        case BPS: {
            noteBps = this->memory[programCounter++ + 1];
            break;
        }
        case RET: {
            running = false;
        }
        }
        programCounter++;
    }
}

double glitched::NoteMachine::getDuration(glitched::NoteMachine::byte dur) {
    return noteDuration / static_cast<double>(noteBps);
}

double glitched::NoteMachine::getVelocity(glitched::NoteMachine::byte dur) { return noteVelocity / 128.0; }

void glitched::NoteMachine::copyAudio(std::vector<double> buffer, uint32_t position) {
    for (int i = 0; i < buffer.size(); i++) {
        audioBuffer[position + i] += buffer[i];
    }
}
