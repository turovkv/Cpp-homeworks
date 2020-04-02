#pragma once


#include <iosfwd>


//==============================================int========================================

class write_le_int32 {
public:
    explicit write_le_int32(const int32_t &data);

    std::ostream &operator()(std::ostream &out) const;

private:
    const int32_t &_data;
};

class read_le_int32 {
public:
    explicit read_le_int32(int32_t &data);

    std::istream &operator()(std::istream &in) const;

private:
    int32_t &_data;
};

std::ostream &operator<<(std::ostream &out, const write_le_int32 &manip);

std::istream &operator>>(std::istream &in, const read_le_int32 &manip);

//==============================================bool=====================================

class write_bool {
public:
    explicit write_bool(const bool &data);

    std::ostream &operator()(std::ostream &out) const;

private:
    const bool &_data;
};

class read_bool {
public:
    explicit read_bool(bool &data);

    std::istream &operator()(std::istream &in) const;

private:
    bool &_data;
};

std::ostream &operator<<(std::ostream &out, const write_bool &manip);

std::istream &operator>>(std::istream &in, const read_bool &manip);

//===========================================std::string=========================================

class write_c_str {
public:
    explicit write_c_str(const std::string &data);

    std::ostream &operator()(std::ostream &out) const;

private:
    const std::string &_data;
};

class read_c_str {
public:
    explicit read_c_str(std::string &data);

    std::istream &operator()(std::istream &in) const;

private:
    std::string &_data;
};

std::ostream &operator<<(std::ostream &out, const write_c_str &manip);

std::istream &operator>>(std::istream &in, const read_c_str &manip);