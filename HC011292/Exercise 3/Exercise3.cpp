#include <iostream>
#include <vector>

using namespace std;

class Polynomial {
protected:
	int degree{}; //Initialize
	vector<double> coefficient{};

public:
	Polynomial() {};
	Polynomial(int deg, vector<double> coef) : degree(deg), coefficient(coef) {}
	~Polynomial() {};
	//Output for the move assignment operator
	friend ostream& operator << (ostream& out, const Polynomial& express)
	{
		for (auto i : express.coefficient) {
			out << i << " ";
		}
		return out;
	}
};

Polynomial f(double c2, double c1, double c0)
{
	std::vector<double> coef = { c0, c1, c2 };
	return Polynomial(coef.size() - 1, coef);
}

int main() {
	vector<double> c1 = { 46.12,12.32,12.78 }; //Just for example
	int d1 = c1.size() - 1;
	Polynomial p1(d1, c1);
	p1 = f(1.0, 2.0, 3.0);
	cout << "The degree of given polynomial is " << d1 <<
		" and the coefficient is " << "\n" << p1 << endl;
	return 0;
}