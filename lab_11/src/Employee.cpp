#include "Employee.hpp"


std::istream &operator>>(std::istream &in, Employee &employee) {
    employee.read(in);
    return in;
}

std::ostream &operator<<(std::ostream &out, const Employee &employee) {
    employee.write(out);
    return out;
}

std::ifstream &operator>>(std::ifstream &in, Employee &employee) {
    employee.read(in);
    return in;
}

std::ofstream &operator<<(std::ofstream &out, const Employee &employee) {
    employee.write(out);
    return out;
}
