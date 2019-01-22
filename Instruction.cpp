//
// Created by tmtoon on 22.01.19.
//

#include <iostream>
#include "Instruction.h"

void InstructionRight::execute(Data &data, unsigned int &data_ptr, unsigned int &instruction_ptr) const {
    ++data_ptr;
    ++instruction_ptr;
}

void InstructionLeft::execute(Data &data, unsigned int &data_ptr, unsigned int &instruction_ptr) const {
    --data_ptr;
    ++instruction_ptr;
}

void InstructionInc::execute(Data &data, unsigned int &data_ptr, unsigned int &instruction_ptr) const {
    ++data;
    ++instruction_ptr;
}

void InstructionDec::execute(Data &data, unsigned int &data_ptr, unsigned int &instruction_ptr) const {
    --data;
    ++instruction_ptr;
}

void InstructionOut::execute(Data &data, unsigned int &data_ptr, unsigned int &instruction_ptr) const {
    std::cout << data.get();
    ++instruction_ptr;
}

void InstructionIn::execute(Data &data, unsigned int &data_ptr, unsigned int &instruction_ptr) const {
    byte c;
    std::cin >> c;
    data.set(c);
    ++instruction_ptr;
}

void InstructionJumpFw::execute(Data &data, unsigned int &data_ptr, unsigned int &instruction_ptr) const {
    if (data.get() == 0) {
        instruction_ptr = *goal;
        return;
    }
    ++instruction_ptr;
}

InstructionJumpFw::InstructionJumpFw(unsigned int* x) : goal(x) {}

void InstructionJumpBw::execute(Data &data, unsigned int &data_ptr, unsigned int &instruction_ptr) const {
    if (data.get() != 0) {
        instruction_ptr = goal;
        return;
    }
    ++instruction_ptr;
}

InstructionJumpBw::InstructionJumpBw(unsigned int x) : goal(x) {}
