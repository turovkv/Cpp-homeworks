#include <iostream>
#include <fstream>
#include "Developer.hpp"
#include "bin_manip.hpp"

int32_t Developer::salary() const {
    int32_t salary = _base_salary;
    if (_has_bonus) { salary += 1000; }
    return salary;
}

void Developer::read(std::istream &in) {
    in >> _name >> _base_salary >> _has_bonus;
}

void Developer::read(std::ifstream &in) {
    in >> read_c_str(_name);
    in >> read_le_int32(_base_salary);
    in >> read_bool(_has_bonus);
}

void Developer::write(std::ostream &out) const {
    out << "Developer\n";
    out << "Name: " << _name << '\n';
    out << "Base Salary: " << _base_salary << '\n';
    out << "Has bonus: " << (_has_bonus ? '+' : '-') << '\n';
}

void Developer::write(std::ofstream &out) const {
    out << write_le_int32(1);
    out << write_c_str(_name);
    out << write_le_int32(_base_salary);
    out << write_bool(_has_bonus);
}
