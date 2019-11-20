//
// Created by xdrie on 11/20/19.
//
#include "NasmAssembler.h"
#include "NoteMachine.h"
#include <iostream>
#include <sstream>
namespace glitched {
NasmAssembler::NasmAssembler(std::ifstream &source) : input(source) {}

glitched::NoteMachine::Instruction parseInstruction(std::string instr) {
    if (instr == "nop") return NoteMachine::NOP;
    else if (instr == "mode") return NoteMachine::MODE;
    else if (instr == "play") return NoteMachine::PLAY;
    else if (instr == "push") return NoteMachine::PUSH;
    else if (instr == "frame") return NoteMachine::FRAME;
    else if (instr == "batch") return NoteMachine::BATCH;
    else if (instr == "rest") return NoteMachine::REST;
    else if (instr == "back") return NoteMachine::BACK;
    else if (instr == "dur") return NoteMachine::DUR;
    else if (instr == "vel") return NoteMachine::VEL;
    else if (instr == "bps") return NoteMachine::BPS;
    else if (instr == "ret") return NoteMachine::RET;

    throw std::runtime_error("instruction '" + instr + "' did not match any known.");
}

void NasmAssembler::assemble(std::ofstream &output) {
    std::string line;
    while (std::getline(input, line)) {
        std::istringstream iss(line);
        // read tokens from line
        std::string op;
        std::int32_t arg;
        if (!(iss >> op)) {
            continue; // blank
        }
        if (op.substr(0, 1) == "#") { // comment
            std::cout << "tk: [#]" << std::endl;
            continue;
        }
        bool has_arg = true;
        if (!(iss >> arg)) {
            has_arg = false;
        }
        std::cout << "tk: [" << op << "], [" << arg << "]" << std::endl;
        // get Instruction item
        auto pkInstr = (uint8_t) parseInstruction(op);
        auto pkArg = (uint8_t) arg;
        output << pkInstr;
        if (has_arg) {
            output << pkArg;
        }
    }
    output << std::flush;
}

}