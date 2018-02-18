#include "rational.h"
#include <algorithm>
#include <numeric>
using std::cout;
using std::endl;

Rational::Rational(long d, long n) : dnom(d), nom(n){
  simplify();
}
//hitta största gemensamma nämnaren och förenkla
void Rational::simplify() {
  int max_d =  std::__gcd(dnom, nom);
  dnom = dnom/max_d;
  nom = nom/max_d;
}
//krossmultiplicera och sen förenkla
Rational Rational::operator+=(const Rational& r) {
  long d1 = dnom * r.nom;
  long d2 = r.dnom * nom;
  dnom = d1 + d2;
  nom = nom * r.nom;
  simplify();
  return *this;
}
//måste vara utanför i h filen för att funka, med två Rationalobjekt i sig
Rational operator+(const Rational& r1, const Rational& r2) {
  Rational temp = r1;
  return temp += r2;
}

ostream& operator<<(ostream& stream, const Rational& rational) {
  stream << rational.dnom;
  // kolla om heltal
  if(rational.nom != 1) {
    stream << "/" << rational.nom;
  }
	return stream;
}
