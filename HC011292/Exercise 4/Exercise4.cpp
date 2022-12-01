#include <iostream>
#include <vector>

using namespace std;

class Polynomial {
public:
	int degree{}; //Initialize
	vector<double> coefficient{};
	Polynomial() {};
	Polynomial(std::initializer_list<double> j) {
		coefficient.assign(j.begin(), j.end());
		degree = j.size() - 1;
	}
	~Polynomial() {};
	Polynomial& operator=(std::initializer_list<double> j) {
		coefficient.assign(j.begin(), j.end());
		return *this;
	}
	//Output 
	friend ostream& operator << (ostream& out, const Polynomial& express)
	{
		for (auto i : express.coefficient) {
			out << i << " ";
		}
		return out;
	}
};

int main() {
	Polynomial p1{ 34.12,123.32,143.61,65.122 }; //Just for example
	cout <<"Degree: "<<p1.degree<<"\n"<<"Coefficient: " << p1<< endl;
	return 0;
}