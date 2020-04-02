#include <fstream>
#include <sstream>
#include "matrix.hpp"

MatrixException::MatrixException(std::string message) : message_(std::move(message)) {}

const char *MatrixException::what() const noexcept {
    return message_.c_str();
}

void Matrix::load(const std::string &fname) {
    std::ifstream in(fname);
    if (!in.good()) {
        throw MatrixException("LOAD: unable to open file.");
    }
    int32_t new_rows;
    int32_t new_cols;
    in >> new_rows >> new_cols;
    if (!in.good() || new_rows <= 0 || new_cols <= 0) {
        throw MatrixException("LOAD: invalid file format.");
    }
    std::vector<std::vector<int32_t>> new_matrix(new_rows, std::vector<int32_t>(new_cols));
    for (int32_t row = 0; row < new_rows; row++) {
        for (int32_t col = 0; col < new_cols; col++) {
            in >> new_matrix[row][col];
            if (!in.good()) {
                throw MatrixException("LOAD: invalid file format.");
            }
        }
    }
    rows_ = new_rows;
    cols_ = new_cols;
    matrix_ = new_matrix;
}

std::string Matrix::print() const {
    std::stringstream out;
    for (int32_t row = 0; row < rows_; row++) {
        for (int32_t col = 0; col < cols_; col++) {
            out << matrix_[row][col] << ' ';
        }
        out << '\n';
    }
    return out.str();
}

void Matrix::add(const Matrix &other) {
    if (rows_ != other.rows_ || cols_ != other.cols_) {
        throw MatrixException("ADD: dimensions do not match.");
    }
    for (int32_t row = 0; row < rows_; row++) {
        for (int32_t col = 0; col < cols_; col++) {
            matrix_[row][col] += other.getElement(row, col);
        }
    }
}

void Matrix::mul(const Matrix &other) {
    if (cols_ != other.rows_) {
        throw MatrixException("MUL: #arg1.columns != #arg2.rows.");
    }
    int32_t new_rows = rows_;
    int32_t new_cols = other.cols_;
    std::vector<std::vector<int32_t>> new_matrix(new_rows, std::vector<int32_t>(new_cols, 0));
    for (int32_t row = 0; row < new_rows; row++) {
        for (int32_t col = 0; col < new_cols; col++) {
            for (int32_t k = 0; k < cols_; k++) {
                new_matrix[row][col] += matrix_[row][k] * other.matrix_[k][col];
            }
        }
    }
    rows_ = new_rows;
    cols_ = new_cols;
    matrix_ = new_matrix;
}

int32_t Matrix::getElement(int32_t row, int32_t col) const {
    if (0 <= row && row < rows_ && 0 <= col && col < cols_) {
        return matrix_[row][col];
    } else {
        throw MatrixException("ACCESS: bad index.");
    }
}
