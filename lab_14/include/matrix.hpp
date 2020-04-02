#pragma once

#include <exception>
#include <vector>

class MatrixException : public std::exception {
public:
    explicit MatrixException(std::string message);
    const char *what() const noexcept override;

private:
    std::string message_;
};

class Matrix {
public:
    void load(const std::string &fname);
    std::string print() const;
    void add(const Matrix &other);
    void mul(const Matrix &other);
    int32_t getElement(int32_t row, int32_t col) const;

private:
    int32_t rows_ = 0;
    int32_t cols_ = 0;
    std::vector<std::vector<int32_t>> matrix_;
};