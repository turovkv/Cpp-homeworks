#include <cassert>
#include "Scheme.hpp"

// TODO
Scheme::Scheme(int capacity) {
    capacity_ = capacity;
    size_ = 0;
    figures_ = new Figure*[capacity];
}

Scheme::~Scheme() {
    for (int i = 0; i < size_; i++) {
        delete figures_[i];
    }
    delete[] figures_;
}

int Scheme::find_index(int id) {
    for (int i = 0; i < size_; i++) {
        if (figures_[i]->get_id() == id)
            return i;
    }
    return -1;
}

void Scheme::push_back_figure(Figure *fg) {
    assert(size_ < capacity_);
    figures_[size_] = fg;
    size_++;
}

void Scheme::remove_figure(int id) {
    int index = find_index(id);
    assert(index != -1);
    delete figures_[index];
    for (int i = index; i < size_ - 1; i++) {
        figures_[i] = figures_[i + 1];
    }
    size_--;
}

void Scheme::print_all_figures() {
    for (int i = 0; i < size_; i++) {
        figures_[i]->print();
    }
}

void Scheme::zoom_figure(int id, int factor) {
    int index = find_index(id);
    assert(index != -1);
    figures_[index]->zoom(factor);
}

Figure* Scheme::is_inside_figure(int x, int y) {
    for (int i = 0; i < size_; i++) {
        if (figures_[i]->is_inside(x, y))
            return figures_[i];
    }
    return nullptr;
}

void Scheme::move(int id, int new_x, int new_y) {
    int index = find_index(id);
    assert(index != -1);
    figures_[index]->move(new_x, new_y);
}

