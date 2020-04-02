#include <iostream>
#include <fstream>
#include "EmployeesArray.hpp"


int main() {
    EmployeesArray data_base;
    std::string command;
    while (std::cin >> command) {
        if (command == "add") {
            data_base.add_one(std::cin);
        }
        if (command == "list") {
            std::cout << data_base;
        }
        if (command == "load") {
            std::string file_name;
            std::cin >> file_name;
            std::ifstream in(file_name);
            data_base.read_all_bin(in);
        }
        if (command == "save") {
            std::string file_name;
            std::cin >> file_name;
            std::ofstream out(file_name);
            data_base.write_all_bin(out);
        }
        if (command == "exit") {
            return 0;
        }
    }
    return 0;
}
