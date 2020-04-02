#include <iostream>
#include <cstring>
#include <utility>
#include <sstream>
#include "my_vector.h"

namespace my_vector {
    template<typename T>
    std::ostream &operator<<(std::ostream &os, const my_vector<T> &vec) {
        for (size_t i = 0; i < vec.size(); i++) {
            os << vec[i];
            if (i < vec.size() - 1)
                os << ' ';
        }
        return os;
    }
} // namespace my_vector
namespace product {
    class Product {
    public:
        Product(std::string name, int quantity, double price) :
                name_(std::move(name)),
                quantity_(quantity),
                price_(price) {}

        friend std::ostream &operator<<(std::ostream &os, const Product &prod);

    private:
        std::string name_;
        int quantity_;
        double price_;
    };

    std::ostream &operator<<(std::ostream &os, const Product &prod) {
        os << prod.name_ << " " << prod.quantity_ << " " << prod.price_;
        return os;
    }
}  // namespace product

namespace tests {
#define DO_CHECK(EXPR) check(EXPR, __func__, __FILE__, __LINE__);

    void check(bool expr, const char *func, const char *filename, size_t lineNum) {
        if (!expr)
            std::cout << func << " has failed in file " << filename << " in line " << lineNum << "\n";
    }

    template<typename T>
    void test_my_vector(T a, T b) {
        { // default constructor
            std::stringstream ss;

            my_vector::my_vector<T> v;
            ss << v;
            DO_CHECK(ss.str() == "");
            DO_CHECK(v.size() == 0);
            DO_CHECK(v.capacity() == 0);
        }
        { // copy constructor
            std::stringstream test_stream;
            std::stringstream correct_stream;

            my_vector::my_vector<T> v1;
            v1.push_back(a);
            my_vector::my_vector<T> v(v1);
            test_stream << v;
            correct_stream << a;
            DO_CHECK(test_stream.str() == correct_stream.str());
            DO_CHECK(v.size() == 1);
            DO_CHECK(v.capacity() == 1);
        }
        { // move constructor
            std::stringstream test_stream;
            std::stringstream correct_stream;

            my_vector::my_vector<T> v1;
            v1.push_back(a);
            my_vector::my_vector<T> v(std::move(v1));
            test_stream << v;
            correct_stream << a;
            DO_CHECK(test_stream.str() == correct_stream.str());
            DO_CHECK(v.size() == 1);
            DO_CHECK(v.capacity() == 1);
        }
        { // copy assign
            std::stringstream test_stream;
            std::stringstream correct_stream;

            my_vector::my_vector<T> v1;
            my_vector::my_vector<T> v2;
            v1.push_back(a);
            v2.push_back(b);
            v1 = v2;
            test_stream << v1;
            correct_stream << v2;
            DO_CHECK(test_stream.str() == correct_stream.str());
            DO_CHECK(v1.size() == v2.size());
            DO_CHECK(v1.capacity() == v2.capacity());
        }
        { // move assign
            std::stringstream test_stream;
            std::stringstream correct_stream;

            my_vector::my_vector<T> v1;
            my_vector::my_vector<T> v2;
            my_vector::my_vector<T> v3;
            v1.push_back(a);
            v2.push_back(b);
            v2.push_back(a);
            v3 = v2;
            v1 = std::move(v2);
            test_stream << v1;
            correct_stream << v3;
            DO_CHECK(test_stream.str() == correct_stream.str());
            DO_CHECK(v1.size() == v3.size());
            DO_CHECK(v1.capacity() == v3.capacity());
        }
        { // fields
            my_vector::my_vector<T> v1;
            DO_CHECK(v1.empty() == 1);
            DO_CHECK(v1.size() == 0);
            DO_CHECK(v1.capacity() == 0);
            v1.push_back(a);
            DO_CHECK(v1.empty() == 0);
            DO_CHECK(v1.size() == 1);
            DO_CHECK(v1.capacity() == 1);
            v1.push_back(b);
            DO_CHECK(v1.empty() == 0);
            DO_CHECK(v1.size() == 2);
            DO_CHECK(v1.capacity() == 2);
            v1.push_back(b);
            DO_CHECK(v1.empty() == 0);
            DO_CHECK(v1.size() == 3);
            DO_CHECK(v1.capacity() == 4);
        }
        { // reserve
            std::stringstream test_stream;
            std::stringstream correct_stream;

            my_vector::my_vector<T> v1;
            v1.push_back(a);
            v1.push_back(b);
            v1.reserve(3);
            test_stream << v1;
            correct_stream << a << ' ' << b;
            DO_CHECK(test_stream.str() == correct_stream.str());
            DO_CHECK(v1.capacity() == 4);
            DO_CHECK(v1.size() == 2);
            v1.reserve(100);
            DO_CHECK(v1.capacity() == 128);
            DO_CHECK(v1.size() == 2);
        }
        { // [ ]
            std::stringstream test_stream;
            std::stringstream correct_stream;

            my_vector::my_vector<T> v1;
            v1.push_back(b);
            v1.push_back(a);
            v1.push_back(a);

            my_vector::my_vector<T> v2;
            v2.push_back(a);
            v2.push_back(b);
            v2.push_back(b);

            my_vector::my_vector<T> v3;
            v3.push_back(a);
            v3.push_back(b);
            v3.push_back(b);

            v1[0] = v2[0];
            v1[1] = v2[1];
            v1[2] = std::move(v2[2]);

            test_stream << v1;
            correct_stream << v3;
            DO_CHECK(test_stream.str() == correct_stream.str());
        }
        { // push_back
            std::stringstream test_stream;
            std::stringstream correct_stream;

            my_vector::my_vector<T> v1;
            v1.push_back(a);
            v1.push_back(b);
            test_stream << v1;
            correct_stream << a << ' ' << b;
            DO_CHECK(test_stream.str() == correct_stream.str());
        }
        { // push_back move
            std::stringstream test_stream;
            std::stringstream correct_stream;

            my_vector::my_vector<T> v1;
            v1.push_back(a);
            v1.push_back(b);

            my_vector::my_vector<T> v2;
            v2.push_back(std::move(v1[0]));
            v2.push_back(std::move(v1[1]));
            test_stream << v2;
            correct_stream << a << ' ' << b;
            DO_CHECK(test_stream.str() == correct_stream.str());
        }
        { //pop_back
            std::stringstream test_stream;
            std::stringstream correct_stream;

            my_vector::my_vector<T> v1;
            v1.push_back(a);
            v1.push_back(b);
            v1.push_back(b);
            v1.push_back(b);
            v1.pop_back();
            v1.pop_back();

            my_vector::my_vector<T> v2;
            v2.push_back(a);
            v2.push_back(b);

            test_stream << v1;
            correct_stream << v2;
            DO_CHECK(test_stream.str() == correct_stream.str());
            DO_CHECK(v1.size() == v2.size());
        }
        { //clear
            my_vector::my_vector<T> v1;
            v1.push_back(a);
            v1.push_back(b);
            v1.push_back(b);
            v1.push_back(b);

            v1.clear();
            DO_CHECK(v1.size() == 0);
        }
    }

    template<typename T>
    void test_my_vector_default_constructible(T a, T b) {
        { // constructor size_t
            std::stringstream test_stream;
            std::stringstream correct_stream;

            my_vector::my_vector<T> v1(3);
            test_stream << v1;
            correct_stream << T() << ' ' << T() << ' ' << T();
            DO_CHECK(test_stream.str() == correct_stream.str());
            DO_CHECK(v1.size() == 3);
            DO_CHECK(v1.capacity() == 4);
        }
        { // resize 1
            std::stringstream test_stream;
            std::stringstream correct_stream;

            my_vector::my_vector<T> v1;
            v1.push_back(a);
            v1.push_back(a);
            v1.push_back(b);

            my_vector::my_vector<T> v2;
            v2.push_back(a);
            v2.push_back(a);

            v1.resize(2);

            test_stream << v1;
            correct_stream << v2;
            DO_CHECK(test_stream.str() == correct_stream.str());
            DO_CHECK(v1.size() == 2);
        }
        { // resize 2
            std::stringstream test_stream;
            std::stringstream correct_stream;

            my_vector::my_vector<T> v1;
            v1.push_back(a);
            v1.push_back(a);
            v1.push_back(b);

            my_vector::my_vector<T> v2;
            v2.push_back(a);
            v2.push_back(a);
            v2.push_back(b);
            v2.push_back(T());
            v2.push_back(T());

            v1.resize(5);

            test_stream << v1;
            correct_stream << v2;
            DO_CHECK(test_stream.str() == correct_stream.str());
            DO_CHECK(v1.size() == 5);
        }
    }
} // namespace tests

int main() {
    tests::test_my_vector<int>(5, 10);
    tests::test_my_vector<product::Product>(product::Product("asdf", 4, 12.0), product::Product("qwe", -1, 7.5));
    tests::test_my_vector_default_constructible(12, 555);
    return 0;
}