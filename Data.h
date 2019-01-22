//
// Created by tmtoon on 22.01.19.
//

#ifndef BRAINFUCK_DATA_HPP
#define BRAINFUCK_DATA_HPP

typedef unsigned char byte;

class Data {
private:
    byte _data;

public:
    Data();

    const byte &operator++();

    const byte &operator--();

    const byte &get();

    void set(const byte &);
};


#endif //BRAINFUCK_DATA_HPP
