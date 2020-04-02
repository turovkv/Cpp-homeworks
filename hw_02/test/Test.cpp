#include <iostream>
#include "Test.hpp"
#include "BoardTest.hpp"

int Test::totalNum = 0;
int Test::failedNum = 0;

void Test::check(bool expr, const char *func, const char *filename, size_t lineNum) {
    totalNum++;
    if (expr) {
        return;
    }
    failedNum++;
    std::cout << func << " has failed in file " << filename << " in line " << lineNum << "\n";
}

bool Test::showFinalResult() {
    std::cout << "Total number of tests: " << totalNum << "\n";
    std::cout << "Passed:  " << totalNum - failedNum << "\n";
    std::cout << "Failed:  " << failedNum << "\n";
    return totalNum == failedNum;
}

int main() {
    BoardTest bt;
    bt.runAllTests();
    Test::showFinalResult();
    return 0;
}
