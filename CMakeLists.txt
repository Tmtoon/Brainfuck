cmake_minimum_required(VERSION 3.13)
project(Brainfuck)

set(CMAKE_CXX_STANDARD 14)

add_executable(Brainfuck main.cpp Data.cpp Data.h Instruction.cpp Instruction.h Program.cpp Program.h BrainfuckVM.cpp BrainfuckVM.h)