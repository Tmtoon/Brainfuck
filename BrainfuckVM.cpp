//
// Created by tmtoon on 22.01.19.
//

#include <iostream>
#include "BrainfuckVM.h"

BrainfuckVM::BrainfuckVM() {
    std::cout << "Brainfuck VM ready for some serious action!" << std::endl;
}

void BrainfuckVM::run(Program &p) {
    data.clear();
    data.resize(30000);
    data_ptr = 0;
    try {
        for (;;) {
            if (not p.execute(data[data_ptr], data_ptr)) {
                break;
            }
        }
        std::cout << std::endl << "Program terminated successfully" << std::endl;
    } catch (const exception &e) {
        std::cout << "Program terminated with error: " << e.what() << std::endl;
    }
}
