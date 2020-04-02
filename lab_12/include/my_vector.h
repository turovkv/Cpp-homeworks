#pragma once

#include <cstddef>

namespace my_vector {
    template<typename T>
    class my_vector {
    public:
        my_vector() = default;
        explicit my_vector(std::size_t n);
        my_vector(const my_vector &other);
        my_vector(my_vector &&other) noexcept;
        my_vector &operator=(const my_vector &other);
        my_vector &operator=(my_vector &&other) noexcept;
        ~my_vector() noexcept = default;

        std::size_t size() const noexcept;
        std::size_t capacity() const noexcept;
        bool empty() const noexcept;

        void resize(std::size_t n);
        void reserve(std::size_t n);

        T &operator[](std::size_t index) noexcept;
        const T &operator[](std::size_t index) const noexcept;

        void push_back(const T &value); //reserve
        void push_back(T &&value);
        void pop_back() noexcept;
        void clear() noexcept;

    private:
        class vector_holder {
        public:
            vector_holder();
            explicit vector_holder(size_t n);
            vector_holder(const vector_holder &other);
            vector_holder(vector_holder &&other) noexcept;
            ~vector_holder() noexcept;

            void swap(vector_holder &other) noexcept;

            size_t capacity_;
            size_t size_; // 'size_' always equal to a number of valid objects in vector
            T *array_;
        };

        vector_holder holder;
    };

}

#include "my_vector_impl.h"
