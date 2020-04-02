#pragma once

#include <memory>
#include <cmath>


namespace my_vector {

    template<typename T>
    my_vector<T>::my_vector(std::size_t n) : holder(n) {
        for (size_t i = 0; i < n; i++) {
            new(&holder.array_[i]) T();
            holder.size_++;
        }
    }

    template<typename T>
    my_vector<T>::my_vector(const my_vector &other) :
            holder(other.holder) {}

    template<typename T>
    my_vector<T>::my_vector(my_vector &&other) noexcept :
            holder(std::move(other.holder)) {}

    template<typename T>
    my_vector <T> &my_vector<T>::operator=(const my_vector &other) {
        vector_holder new_holder(other.holder);
        holder.swap(new_holder);
        return *this;
    }

    template<typename T>
    my_vector <T> &my_vector<T>::operator=(my_vector &&other) noexcept {
        holder.swap(other.holder);
        return *this;
    }

    template<typename T>
    void my_vector<T>::push_back(const T &value) {
        push_back(std::move(T(value)));
    }

    template<typename T>
    void my_vector<T>::push_back(T &&value) {
        reserve(size() + 1);
        new(&holder.array_[size()]) T(std::move(value));
        holder.size_++;
    }

    template<typename T>
    std::size_t my_vector<T>::size() const noexcept {
        return holder.size_;
    }

    template<typename T>
    std::size_t my_vector<T>::capacity() const noexcept {
        return holder.capacity_;
    }

    template<typename T>
    bool my_vector<T>::empty() const noexcept {
        return holder.size_ == 0;
    }

    template<typename T>
    void my_vector<T>::resize(std::size_t n) {
        while (size() > n)
            pop_back();
        while (size() < n)
            push_back(T());
    }

    template<typename T>
    void my_vector<T>::reserve(std::size_t n) {
        if (holder.capacity_ >= n)
            return;
        vector_holder new_holder(n);
        for (size_t i = 0; i < size(); i++) {
            new(&new_holder.array_[i]) T(std::move(holder.array_[i]));
            new_holder.size_++;
        }
        holder.swap(new_holder);
    }

    template<typename T>
    T &my_vector<T>::operator[](std::size_t index) noexcept {
        return holder.array_[index];
    }

    template<typename T>
    const T &my_vector<T>::operator[](std::size_t index) const noexcept {
        return holder.array_[index];
    }

    template<typename T>
    void my_vector<T>::pop_back() noexcept {
        holder.array_[size() - 1].~T();
        holder.size_--;
    }

    template<typename T>
    void my_vector<T>::clear() noexcept {
        while (size()) {
            pop_back();
        }
    }

    template<typename T>
    my_vector<T>::vector_holder::vector_holder() :
            capacity_(0),
            size_(0),
            array_(nullptr) {}

    template<typename T>
    my_vector<T>::vector_holder::vector_holder(size_t n) :
            capacity_((size_t) 1 << (size_t) ceil(log2(n))),
            size_(0),
            array_(reinterpret_cast<T *>(new char[capacity_ * sizeof(T)])) {}

    template<typename T>
    my_vector<T>::vector_holder::vector_holder(const my_vector::vector_holder &other) :
            capacity_(other.size_),
            size_(0),
            array_(reinterpret_cast<T *>(new char[other.size_ * sizeof(T)])) {
        for (size_t i = 0; i < other.size_; i++) {
            new(&array_[i]) T(other.array_[i]);
            size_++;
        }
    }

    template<typename T>
    my_vector<T>::vector_holder::vector_holder(my_vector::vector_holder &&other) noexcept :
            capacity_(0),
            size_(0),
            array_(nullptr) {
        swap(other);
    }

    template<typename T>
    my_vector<T>::vector_holder::~vector_holder() noexcept {
        while (size_) {
            array_[size_ - 1].~T();
            size_--;
        }
        delete[] reinterpret_cast<char *>(array_);
    }

    template<typename T>
    void my_vector<T>::vector_holder::swap(my_vector::vector_holder &other) noexcept {
        std::swap(capacity_, other.capacity_);
        std::swap(size_, other.size_);
        std::swap(array_, other.array_);
    }
}