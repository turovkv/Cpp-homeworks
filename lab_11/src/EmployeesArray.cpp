#include <iostream>
#include <fstream>
#include <cassert>
#include "EmployeesArray.hpp"
#include "bin_manip.hpp"
#include "Developer.hpp"
#include "SalesManager.hpp"


int32_t EmployeesArray::total_salary() const {
    int32_t sum = 0;
    for (auto employee : _employees) {
        sum += employee->salary();
    }
    return sum;
}

void EmployeesArray::add_one(std::istream &in) {
    Employee *employee = nullptr;
    int32_t type;
    in >> type;
    if (type == 1) {
        employee = new Developer;
    }
    if (type == 2) {
        employee = new SalesManager;
    }
    assert(employee != nullptr);
    employee->read(in);
    _employees.push_back(employee);
}

void EmployeesArray::read_all_bin(std::ifstream &in) {
    int32_t size;
    in >> read_le_int32(size);
    for (int32_t i = 0; i < size; i++) {
        Employee *employee = nullptr;
        int32_t type;
        in >> read_le_int32(type);
        if (type == 1) {
            employee = new Developer;
        }
        if (type == 2) {
            employee = new SalesManager;
        }
        assert(employee != nullptr);
        employee->read(in);
        _employees.push_back(employee);
    }
}

void EmployeesArray::write_all_txt(std::ostream &out) const {
    for (size_t i = 0; i < _employees.size(); i++) {
        out << i + 1 << ". " << *_employees[i];
    }
    out << "== Total salary: " << total_salary() << '\n';
}

void EmployeesArray::write_all_bin(std::ofstream &out) const {
    out << write_le_int32(_employees.size());
    for (auto employee : _employees) {
        out << *employee;
    }
}

EmployeesArray::~EmployeesArray() {
    for (auto employee : _employees) {
        delete employee;
    }
}

std::ostream &operator<<(std::ostream &out, const EmployeesArray &arr) {
    arr.write_all_txt(out);
    return out;
}

std::ofstream &operator<<(std::ofstream &out, const EmployeesArray &arr) {
    arr.write_all_bin(out);
    return out;
}