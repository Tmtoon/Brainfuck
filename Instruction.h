//
// Created by tmtoon on 22.01.19.
//

#ifndef BRAINFUCK_INSTRUCTION_HPP
#define BRAINFUCK_INSTRUCTION_HPP

#include "Data.h"

class Instruction {
public:
    virtual void execute(Data& data, unsigned int& data_ptr, unsigned int& instruction_ptr) const = 0;

};

class InstructionRight : public Instruction {
public:
    void execute(Data& data, unsigned int& data_ptr, unsigned int& instruction_ptr) const override;
};

class InstructionLeft : public Instruction {
public:
    void execute(Data& data, unsigned int& data_ptr, unsigned int& instruction_ptr) const override;
};

class InstructionInc : public Instruction {
public:
    void execute(Data& data, unsigned int& data_ptr, unsigned int& instruction_ptr) const override;
};

class InstructionDec : public Instruction {
public:
    void execute(Data& data, unsigned int& data_ptr, unsigned int& instruction_ptr) const override;
};

class InstructionOut : public Instruction {
public:
    void execute(Data& data, unsigned int& data_ptr, unsigned int& instruction_ptr) const override;
};

class InstructionIn : public Instruction {
public:
    void execute(Data& data, unsigned int& data_ptr, unsigned int& instruction_ptr) const override;
};

class InstructionJumpFw : public Instruction {
private:
    unsigned int* goal;

public:
    explicit InstructionJumpFw(unsigned int* x);

    ~InstructionJumpFw() { delete goal; }

    void execute(Data& data, unsigned int& data_ptr, unsigned int& instruction_ptr) const override;
};

class InstructionJumpBw : public Instruction {
private:
    unsigned int goal;

public:
    explicit InstructionJumpBw(unsigned int x);

    void execute(Data& data, unsigned int& data_ptr, unsigned int& instruction_ptr) const override;
};
#endif //BRAINFUCK_INSTRUCTION_HPP
