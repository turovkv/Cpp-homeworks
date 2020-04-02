#include <iostream>
#include <fstream>
#include "SalesManager.hpp"
#include "bin_manip.hpp"


int32_t SalesManager::salary() const {
    return _base_salary + (int) (_sold_nm * _price * 0.01);
}

void SalesManager::read(std::istream &in) {
    in >> _name >> _base_salary >> _sold_nm >> _price;
}

void SalesManager::read(std::ifstream &in) {
    in >> read_c_str(_name);
    in >> read_le_int32(_base_salary);
    in >> read_le_int32(_sold_nm);
    in >> read_le_int32(_price);
}

void SalesManager::write(std::ostream &out) const {
    out << "Sales Manager\n";
    out << "Name: " << _name << '\n';
    out << "Base Salary: " << _base_salary << '\n';
    out << "Sold items: " << _sold_nm << '\n';
    out << "Item price: " << _price << '\n';
}

void SalesManager::write(std::ofstream &out) const {
    out << write_le_int32(2);
    out << write_c_str(_name);
    out << write_le_int32(_base_salary);
    out << write_le_int32(_sold_nm);
    out << write_le_int32(_price);
}
