//
// Created by kirill on 17/01/2020.
//
#include <iostream>
#include <fstream>
#include "bin_manip.hpp"


//========================================int========================================

write_le_int32::write_le_int32(const int32_t &data) : _data(data) {}

std::ostream &write_le_int32::operator()(std::ostream &out) const {
    int32_t cur_data = _data;
    for (char i = 0; i < 4; i++) {
        unsigned char byte = cur_data % 256;
        cur_data /= 256;
        out.write((const char *) (&byte), 1);
    }
    return out;
}

read_le_int32::read_le_int32(int32_t &data) : _data(data) {}


std::istream &read_le_int32::operator()(std::istream &in) const {
    int32_t cur_data = 0;
    int64_t offset = 1;
    for (char i = 0; i < 4; i++) {
        unsigned char byte = 0;
        in.read((char *) (&byte), 1);
        cur_data += byte * offset;
        offset *= 256;
    }
    _data = cur_data;
    return in;
}

std::ostream &operator<<(std::ostream &out, const write_le_int32 &manip) {
    return manip(out);
}

std::istream &operator>>(std::istream &in, const read_le_int32 &manip) {
    return manip(in);
}

//=====================================bool===================================

write_bool::write_bool(const bool &data) : _data(data) {}

std::ostream &write_bool::operator()(std::ostream &out) const {
    out.write((const char *) (&_data), sizeof(bool));
    return out;
}

read_bool::read_bool(bool &data) : _data(data) {}

std::istream &read_bool::operator()(std::istream &in) const {
    in.read((char *) (&_data), sizeof(bool));
    return in;
}

std::ostream &operator<<(std::ostream &out, const write_bool &manip) {
    return manip(out);
}

std::istream &operator>>(std::istream &in, const read_bool &manip) {
    return manip(in);
}

//=====================================std::string=========================================


write_c_str::write_c_str(const std::string &data) : _data(data) {}

std::ostream &write_c_str::operator()(std::ostream &out) const {
    out.write(_data.c_str(), _data.size() + 1);
    return out;
}

read_c_str::read_c_str(std::string &data) : _data(data) {}

std::istream &read_c_str::operator()(std::istream &in) const {
    while (in.good()) {
        char c = in.get();
        if (!c) break;
        _data += c;
    }
    return in;
}

std::ostream &operator<<(std::ostream &out, const write_c_str &manip) {
    return manip(out);
}

std::istream &operator>>(std::istream &in, const read_c_str &manip) {
    return manip(in);
}