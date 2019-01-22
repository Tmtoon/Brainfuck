//
// Created by tmtoon on 22.01.19.
//

#ifndef BRAINFUCK_BRAINFUCKVM_HPP
#define BRAINFUCK_BRAINFUCKVM_HPP


#include "Program.h"

class BrainfuckVM {
private:
    std::vector<Data> data;
    unsigned int data_ptr;

public:
    BrainfuckVM();

    void run(Program& p);

};


#endif //BRAINFUCK_BRAINFUCKVM_HPP
