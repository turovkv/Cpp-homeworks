#include <iostream>
#include "Rectangle.hpp"

Rectangle::Rectangle(int id, int x, int y, int width, int height) : Figure(id, x, y) {
    width_ = width;
    height_ = height;
}

void Rectangle::print() const {
    std::cout << "Rectangle " << id_ << ":";
    std::cout << " x = " << x_;
    std::cout << " y = " << y_;
    std::cout << " width = " << width_;
    std::cout << " height = " << height_;
    std::cout << "\n";
}

bool Rectangle::is_inside(int x, int y) const {
    bool is  = true;
    if (x_ * 2 - width_  > x * 2) is = false;
    if (x_ * 2 + width_  < x * 2) is = false;
    if (y_ * 2 - height_ > y * 2) is = false;
    if (y_ * 2 + height_ < y * 2) is = false;
    return is;
}

void Rectangle::zoom(int factor) {
    width_ *= factor;
    height_ *= factor;
}

