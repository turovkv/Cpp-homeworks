#pragma once

#include "Employee.hpp"

class SalesManager : public Employee {
public:
    int32_t salary() const override;

    void read(std::istream &in) override;

    void read(std::ifstream &in) override;

    void write(std::ostream &out) const override;

    void write(std::ofstream &out) const override;

private:
    int32_t _sold_nm = 0;
    int32_t _price = 0;
};