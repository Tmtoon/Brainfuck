//
// Created by tmtoon on 22.01.19.
//

#include <fstream>
#include <stack>
#include "Program.h"

Program::Program(const std::string &file_name) {
    using std::make_unique;
    instruction_ptr = 0; // start instruction pointer at 0
    std::ifstream file(file_name); // open file
    std::vector<unsigned int*> fw; // used for [ -> ]
    fw.emplace_back(new unsigned int());
    unsigned int fw_index = 0;
    std::stack<unsigned int> bw_stack; // used for [ <- ]
    char c; // char to read
    while(file.get(c)) {
        switch (c) {
            case '>':
                instructions.emplace_back(make_unique<InstructionRight>());
                break;

            case '<':
                instructions.emplace_back(make_unique<InstructionLeft>());
                break;

            case '+':
                instructions.emplace_back(make_unique<InstructionInc>());
                break;

            case '-':
                instructions.emplace_back(make_unique<InstructionDec>());
                break;

            case '.':
                instructions.emplace_back(make_unique<InstructionOut>());
                break;

            case ',':
                instructions.emplace_back(make_unique<InstructionIn>());
                break;

            case '[':
                bw_stack.push(instructions.size());
                instructions.emplace_back(make_unique<InstructionJumpFw>(fw[fw_index]));
                fw.emplace_back(new unsigned int());
                break;

            case ']':
                *fw[fw_index] = instructions.size();
                instructions.emplace_back(make_unique<InstructionJumpBw>(bw_stack.top()));
                ++fw_index;
                bw_stack.pop();
                break;

            case '\n':
            case ' ':
                break;

            default:
                throw invalid_input();
        }
    }

    file.close(); // close file
}

bool Program::execute(Data &data, unsigned int &data_ptr) {
    if (instructions.empty()) {
        throw no_instructions();
    }
    if (instruction_ptr == instructions.size()) {
        return false;
    }
    if (instruction_ptr > instructions.size()) {
        throw out_of_range();
    }
    instructions[instruction_ptr]->execute(data, data_ptr, instruction_ptr);
    return true;
}
