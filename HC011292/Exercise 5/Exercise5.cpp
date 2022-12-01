#include <vector>
#include <stdexcept>
#include <cassert>
#include <iostream>

namespace Kenneth {
    template <typename T>
    class stack {
    public:
        stack() { dat.reserve(cap); }

        T top() { return dat.at(dat.size() - 1); }
        void pop() {
            if (empty()) {
                throw std::underflow_error("Stack under-flowed!");
            }
            else {
                dat.pop_back();
            }
        }

        void push(T& a) {
            if (full()) {
                throw std::overflow_error("Stack over-flowed!");
            }
            else {
                dat.push_back(a);
            }
        }

        void clear() { dat.clear(); }
        std::size_t size() { return dat.size(); }

        bool full() const noexcept { return cap == dat.size(); }
        bool empty() const noexcept { return 0 == dat.size(); }

    private:
        std::size_t cap = 10;
        std::vector<T> dat;
    };
}

int main() {
    using namespace Kenneth;
    stack<int> example;
    for (int i = 1; i < 10; ++i) { //Just take it to 9 for example 
        example.push(i);
    }
    std::cout << example.size() << std::endl;
    std::cout << example.full() << std::endl;
    example.pop();
    std::cout << example.top() << std::endl;
    example.clear();
    std::cout << example.empty() << std::endl;
    return 0;
}