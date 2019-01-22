//
// Created by tmtoon on 22.01.19.
//

#ifndef BRAINFUCK_PROGRAM_HPP
#define BRAINFUCK_PROGRAM_HPP

#include <vector>
#include <iostream>
#include <memory>
#include "Data.h"
#include "Instruction.h"

struct exception {
    virtual const char* what() const = 0;
};

struct invalid_input : public exception {
    const char* what() const override { return "invalid input"; }
};

struct no_instructions : public exception {
    const char* what() const override { return "no instructions"; }
};

struct out_of_range : public exception {
    const char* what() const override { return "out of range"; }
};

class Program {
private:
    std::vector<std::unique_ptr<Instruction>> instructions;
    unsigned int instruction_ptr;

public:
    explicit Program(const std::string &);

    bool execute(Data &data, unsigned int &data_ptr);

};


#endif //BRAINFUCK_PROGRAM_HPP
