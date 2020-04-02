#include <iostream>
#include "matrix.hpp"

int main() {
    const int32_t REGISTERS = 10;
    std::vector<Matrix> matrix(REGISTERS);

    while (true) {
        try {
            std::string command;
            std::cin >> command;
            if (command == "load") {
                char dollar_sign;
                int32_t reg;
                std::string fname;
                std::cin >> dollar_sign >> reg >> fname;
                matrix[reg].load(fname);
            }
            if (command == "print") {
                char dollar_sign;
                int32_t reg;
                std::cin >> dollar_sign >> reg;
                std::cout << matrix[reg].print();
            }
            if (command == "add") {
                char dollar_sign;
                int32_t reg1, reg2;
                std::cin >> dollar_sign >> reg1 >> dollar_sign >> reg2;
                matrix[reg1].add(matrix[reg2]);
            }
            if (command == "mul") {
                char dollar_sign;
                int32_t reg1, reg2;
                std::cin >> dollar_sign >> reg1 >> dollar_sign >> reg2;
                matrix[reg1].mul(matrix[reg2]);
            }
            if (command == "elem") {
                char dollar_sign;
                int32_t reg, row, col;
                std::cin >> dollar_sign >> reg >> row >> col;
                std::cout << matrix[reg].getElement(row, col) << '\n';
            }
            if (command == "exit") {
                break;
            }
        } catch (const MatrixException &e) {
            std::cout << e.what() << std::endl;
        } catch (const std::bad_alloc &e) {
            std::cout << "Unable to allocate memory." << std::endl;
        }
    }
    return 0;
}