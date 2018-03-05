/*
 * Class Rational: a class for rational numbers. Currently only
 * supports +=, +, and <<.
 */

#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>

class Rational {
	friend std::ostream& operator<<(std::ostream&, const Rational&);
public:
	Rational(long n = 0, long d = 1);
	Rational& operator+=(const Rational& r);
private:
	long num;   // numerator
	long denom; // denominator
	void simplify();      // simplify to lowest terms
	long gcd(long, long); // greatest common divisor
};

Rational operator+(const Rational& lhs, const Rational& rhs);

std::ostream& operator<<(std::ostream& os, const Rational& r);

#endif
