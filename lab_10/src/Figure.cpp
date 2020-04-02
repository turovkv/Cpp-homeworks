#include "Figure.hpp"

Figure::Figure(int id, int x, int y) : id_(id), x_(x), y_(y) {}

int Figure::get_id() const {
    return id_;
}

void Figure::move(int new_x, int new_y) {
    x_ = new_x;
    y_ = new_y;
}
