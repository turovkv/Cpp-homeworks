#ifndef MY_ARRAY_H_
#define MY_ARRAY_H_

#include <cstddef>
#include <stdexcept>
#include <climits>

namespace lab_13 {

    template<typename T, std::size_t N>
    class my_array {
    public:

        T& at(std::size_t index);
        const T& at(std::size_t index) const;
        T& operator[](std::size_t index) noexcept;
        const T& operator[](std::size_t index) const noexcept;

        constexpr bool empty() const noexcept;
        constexpr std::size_t size() const noexcept;

        void fill(const T& value);

    private:
        T data_[N];
    };

    template<std::size_t N>
    class my_array<bool, N> {
    private:
        char data_[(N + CHAR_BIT - 1) / CHAR_BIT];

    private:
        class proxy{
        public:
            explicit proxy(char *byte, std::size_t bit);
            proxy& operator= (bool value);
            proxy& operator= (const proxy& other);
            operator bool() const;
        private:
            char *byte_;
            std::size_t bit_;
        };

    public:
        proxy at(std::size_t index);
        bool at(std::size_t index) const;
        proxy operator[](std::size_t index) noexcept;
        bool operator[](std::size_t index) const noexcept;

        constexpr bool empty() const noexcept;
        constexpr std::size_t size() const noexcept;

        void fill(bool value);
    };

    template<typename T, std::size_t N>
    T &my_array<T, N>::at(std::size_t index) {
        if (0 <= index && index < size()) {
            return data_[index];
        } else {
            throw std::out_of_range("my_array<X>::at() : index is out of range");
        }
    }

    template<typename T, std::size_t N>
    const T &my_array<T, N>::at(std::size_t index) const {
        if (0 <= index && index < size()) {
            return data_[index];
        } else {
            throw std::out_of_range("my_array<X>::at() : index is out of range");
        }
    }

    template<typename T, std::size_t N>
    T &my_array<T, N>::operator[](std::size_t index) noexcept {
        return data_[index];
    }

    template<typename T, std::size_t N>
    const T &my_array<T, N>::operator[](std::size_t index) const noexcept {
        return data_[index];
    }

    template<typename T, std::size_t N>
    constexpr bool my_array<T, N>::empty() const noexcept {
        return size() == 0;
    }

    template<typename T, std::size_t N>
    constexpr std::size_t my_array<T, N>::size() const noexcept {
        return N;
    }

    template<typename T, std::size_t N>
    void my_array<T, N>::fill(const T &value) {
        for (std::size_t index = 0; index < N; index++) {
            data_[index] = value;
        }
    }
//----------------------------------------bool-------------------------------
    template<std::size_t N>
    my_array<bool, N>::proxy::proxy(char *byte, std::size_t bit) :
        byte_(byte), bit_(bit) {}

    template<std::size_t N>
    typename my_array<bool, N>::proxy &my_array<bool, N>::proxy::operator=(bool value) {
        *byte_ &= ~(1u  << bit_);
        *byte_ |= value << bit_;
        return *this;
    }

    template<std::size_t N>
    typename my_array<bool, N>::proxy &my_array<bool, N>::proxy::operator=(const proxy& other) {
        operator=((bool)other);
        return *this;
    }

    template<std::size_t N>
    my_array<bool, N>::proxy::operator bool() const {
        return *byte_ & (1u << bit_);
    }

    template<std::size_t N>
    typename my_array<bool, N>::proxy my_array<bool, N>::at(std::size_t index) {
        if (0 <= index && index < size()) {
            return operator[](index);
        } else {
            throw std::out_of_range("my_array<X>::at() : index is out of range");
        }
    }

    template<std::size_t N>
    bool my_array<bool, N>::at(std::size_t index) const {
        if (0 <= index && index < size()) {
            return operator[](index);
        } else {
            throw std::out_of_range("my_array<X>::at() : index is out of range");
        }
    }

    template<std::size_t N>
    typename my_array<bool, N>::proxy my_array<bool, N>::operator[](std::size_t index) noexcept {
        return proxy(&data_[index / CHAR_BIT], index % CHAR_BIT);
    }

    template<std::size_t N>
    bool my_array<bool, N>::operator[](std::size_t index) const noexcept {
        return (data_[index / CHAR_BIT]) & (index % CHAR_BIT);
    }

    template<std::size_t N>
    constexpr bool my_array<bool, N>::empty() const noexcept {
        return size() == 0;
    }

    template<std::size_t N>
    constexpr std::size_t my_array<bool, N>::size() const noexcept {
        return N;
    }

    template<std::size_t N>
    void my_array<bool, N>::fill(bool value) {
        for (std::size_t index = 0; index < N; index++) {
            operator[](index) = value;
        }
    }
}  // namespace lab_13

#endif  // MY_ARRAY_H_