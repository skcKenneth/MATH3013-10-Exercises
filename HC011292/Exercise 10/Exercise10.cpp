#include <iostream>
#include <vector>
#include <cassert>

template<typename T>
class vector_expression {
	void check_size(int that_size) const { assert(my_size == that_size); }
	void check_index(int i) const { assert(i < my_size); }
public:
	vector_expression(int my_size = 0) : my_size(my_size), dat(new T[my_size]) {};
	const T& operator()(int i) const
	{
		check_index(i);
		return dat[i];
	}

	T& operator()(int i)
	{
		check_index(i);
		return dat[i];
	}
	int size() { return my_size; }
	int size() const { return my_size; }

private:
	int my_size;
	std::unique_ptr<T[]> dat;
};

class ones
	:public vector_expression<int> 
{
public:
	ones(int my_size) : my_size(my_size), dat(new int[my_size]), vector_expression{ my_size } {
		for (int i = 0; i != my_size; ++i) {
			(*this)(i) = 1;
		}
	}
private:
	int my_size;
	std::unique_ptr<int[]> dat;
};

int main()
{
	int x = 0;
	std::cout << "Please input the value of the vector size" << std::endl;
	std::cin >> x;
	std::vector<double> vec(x);
	for (int i = 0; i < x;++i) {
		vec[i] = static_cast<unsigned __int64>(i) + 1;
	}
	ones v_1{ x };

	for (int i = 0; i != x; ++i) {
		std::cout << vec[i] << " "<< v_1(i) << std::endl;
	}
	return 0;
}
