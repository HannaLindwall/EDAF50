#include "rational.h"
#include <iostream>

using namespace std;

int main() {
	Rational a(50, 75); // numerator / denominator
	Rational b(3);      // numerator / 1
	Rational c;         // 0 / 1

	cout << a << "\t(2/3)" << endl;
	cout << b << "\t(3)" << endl;
	cout << c << "\t(0)" << endl;

	c = 1;
	cout << "c=1" << endl;
	b += c;
	cout << "b+=c" << endl;
	c = a + b;
	cout << "c=a+b : " << c << endl;
	cout << b << "\t(4)" << endl;
	cout << a + b + c << "\t(28/3)" << endl;
	cout << a + b + c + 1 << "\t(31/3)" << endl;
}
