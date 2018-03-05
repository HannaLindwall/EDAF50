#include "rational.h"

#include <iostream>
#include <stdexcept>

using namespace std;

Rational::Rational(long n, long d) : num(n), denom(d) {
	if (d == 0) {
		throw invalid_argument("Rational(n,d): d == 0");
	}
	simplify();
}

Rational& Rational::operator+=(const Rational& r) {
	num = num * r.denom + denom * r.num;
	denom *= r.denom;
	simplify();
	return *this;
}

Rational operator+(const Rational& r1, const Rational& r2) {
	Rational local = r1;
	return local += r2;
}

std::ostream& operator<<(ostream& os, const Rational& r) {
	os << r.num;
	if (r.denom != 1) {
		os << '/' << r.denom;
	}
	return os;
}

void Rational::simplify() {
	long divisor = gcd(num, denom);
	num /= divisor;
	denom /= divisor;
}

long Rational::gcd(long u, long v) {
	/*
	 * This is the binary gcd algorithm from NIST
	 * http://www.nist.gov/dads/HTML/binaryGCD.html
	 */
	long g = 1;
	while ((u & 0x1) == 0 && (v & 0x1) == 0) {
		u >>= 1;
		v >>= 1;
		g <<= 1;
	}
	while (u > 0) {
		if ((u & 0x1) == 0) {
			u >>= 1;
		} else if ((v & 0x1) == 0) {
			v >>= 1;
		} else {
			long t = (u - v) >> 1;
			if (t < 0) {
				t = -t;
			}
			if (u < v) {
				v = t;
			} else {
				u = t;
			}
		}
	}
	return g * v;
}
