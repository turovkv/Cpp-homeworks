#pragma once

#include <cstdint>
#include <iosfwd>
#include <string>

class Employee {
public:
    virtual int32_t salary() const = 0;

    virtual void read(std::istream &in) = 0;

    virtual void read(std::ifstream &in) = 0;

    virtual void write(std::ostream &out) const = 0;

    virtual void write(std::ofstream &out) const = 0;

    virtual ~Employee() = default;

protected:
    int32_t _base_salary = 0;
    std::string _name = "";
};

std::istream &operator>>(std::istream &in, Employee &employee);

std::ostream &operator<<(std::ostream &out, const Employee &employee);

std::ifstream &operator>>(std::ifstream &in, Employee &employee);

std::ofstream &operator<<(std::ofstream &out, const Employee &employee);
