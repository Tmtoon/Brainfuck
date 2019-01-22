//
// Created by tmtoon on 22.01.19.
//

#include "Data.h"

Data::Data() : _data(0) {}

const byte &Data::operator++() {
    return ++_data;
}

const byte &Data::operator--() {
    return --_data;
}

const byte &Data::get() {
    return _data;
}

void Data::set(const byte &b) {
    _data = b;
}
