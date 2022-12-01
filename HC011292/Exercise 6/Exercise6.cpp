#include <algorithm>
#include <cassert>
#include<iostream>
namespace Kenneth {
    template <typename T>
    class vector {
    public:

        vector(std::initializer_list<T> k) {
            size = k.size();
            data = new T[size];
            std::copy(k.begin(), k.end(), begin());
        }

        ~vector() { delete[] data; }

        T* begin() { return data; }
        const T* begin() const noexcept { return data; }

        T* end() { return data + size; }
        const T* end() const noexcept { return data + size; }

    private:
        std::size_t size{};
        T* data{};
    };

} 

int main() {
    Kenneth::vector<int> v_temp{ 2, 0, 1 }; //Just take a easy example for checking the function
                                            //of the class
    std::sort(v_temp.begin(), v_temp.end());

    std::cout << *(v_temp.begin()) << " " << *(v_temp.end() - 1);
    return 0;
}