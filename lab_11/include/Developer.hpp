#pragma once

#include "Employee.hpp"

class Developer : public Employee {
public:
    int32_t salary() const override;

    void read(std::istream &in) override;

    void read(std::ifstream &in) override;

    void write(std::ostream &out) const override;

    void write(std::ofstream &out) const override;

private:
    bool _has_bonus = false;
};