#include <cassert>

namespace Kenneth {

	class odd_iterator {
	public:
		odd_iterator() { i = 1; }

		explicit odd_iterator(int k) {
			if (k % 2 == 0) {
				throw "Cannot initialize with even numbers, need to change your value.";
			}
			else {
				i = k;
			}
		}

		odd_iterator(const odd_iterator& j) { i = j.i; }

		odd_iterator& operator=(const odd_iterator& j) {
			i = j.i;
			return *this;
		}

		odd_iterator& operator++() {
			i += 2;
			return *this;
		}

		odd_iterator operator++(int dummy) {
			odd_iterator tmp_file = *this;
			++(*this);
			return tmp_file;
		}

		int operator*() { return i; }

		bool operator==(const odd_iterator& j) { return i == j.i; }

		bool operator!=(const odd_iterator& j) { return !(*this == j); }

	protected:
		int i;
	};

}

int main() {
	using namespace Kenneth;

	odd_iterator a;
	assert(*(a) == 1);

	//odd_iterator b_w(4); // Take a example of even number to show error
	//assert(*b_w == 4);
	odd_iterator b(3);
	assert(*b == 3);

	odd_iterator c(b);
	assert(c == b);

	odd_iterator d;
	d = c;
	assert(d == c);

	odd_iterator e;
	assert(*(e) == 1);
	assert(*(++e) == 3);
	assert(*(e++) == 3);
	assert(*e == 5);

	d = e;
	++d;
	assert(e != d);
}