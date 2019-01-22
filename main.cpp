#include <iostream>
#include "BrainfuckVM.h"

int main() {
    BrainfuckVM bf;
    Program p("test.bf");
    Program p2("test_jump_bw.bf");
    Program p3("test_jump_fw.bf");
    Program p4("example.bf");


    bf.run(p);
    bf.run(p2);
    bf.run(p3);
    bf.run(p4);
    return 0;
}