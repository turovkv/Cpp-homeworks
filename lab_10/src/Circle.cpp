#include <iostream>
#include <cstring>
#include "Circle.hpp"

Circle::Circle(int id, int x, int y, int radius, const char *label) : Figure(id, x, y) {
    radius_ = radius;
    label_ = new char[strlen(label) + 1];
    strcpy(label_, label);
}

Circle::~Circle() {
    delete[] label_;
}

void Circle::print() const {
    std::cout << "Circle " << id_ << ":";
    std::cout << " x = " << x_;
    std::cout << " y = " << y_;
    std::cout << " radius = " << radius_;
    std::cout << " label = " << label_;
    std::cout << "\n";
}

bool Circle::is_inside(int x, int y) const {
    int sqr_dist_x = (x_ - x) * (x_ - x);
    int sqr_dist_y = (y_ - y) * (y_ - y);
    int sqr_radius = radius_ * radius_;
    return sqr_dist_x + sqr_dist_y <= sqr_radius;
}

void Circle::zoom(int factor) {
    radius_ *= factor;
}
