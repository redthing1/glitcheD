//
// Created by xdrie on 11/20/19.
//
#pragma once

#include <fstream>
namespace glitched {
class NasmAssembler {
  private:
    std::ifstream &input;

  public:
    NasmAssembler(std::ifstream &source);
    void assemble(std::ofstream &output);
};
}