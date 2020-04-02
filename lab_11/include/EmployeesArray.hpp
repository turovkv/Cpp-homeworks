#include <cstdint>
#include <vector>
#include "Employee.hpp"


class EmployeesArray {
public:
    int32_t total_salary() const;

    void add_one(std::istream &in);

    void read_all_bin(std::ifstream &in);

    void write_all_txt(std::ostream &out) const;

    void write_all_bin(std::ofstream &out) const;

    ~EmployeesArray();

private:
    std::vector<Employee *> _employees = {};
};

std::ofstream &operator<<(std::ofstream &out, const EmployeesArray &arr);

std::ostream &operator<<(std::ostream &out, const EmployeesArray &arr);
