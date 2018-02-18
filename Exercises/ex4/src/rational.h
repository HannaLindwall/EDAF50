#ifndef RATIONAL_H
#define RATIONAL_H
#include <iostream>
using std::ostream;

class Rational{
public:
  friend ostream& operator<<(ostream& stream, const Rational& rational);
  Rational(long d = 0, long n = 1);
  Rational operator+=(const Rational& r);
private:
  long nom;
  long dnom;
  void simplify();
};
//måste vara utanför i h filen för att funka, med två Rationalobjekt i sig
//varför?????????
Rational operator+(const Rational& r1, const Rational& r2);
#endif
