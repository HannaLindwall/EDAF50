#include <iostream>
#include <string>
#include <algorithm>
#include "primefinder.h"

using std::size_t;
using std::cout;
using std::vector;

Primefinder::Primefinder(size_t m) {
  primes = "CC" + string(m - 1, 'P');
}

string Primefinder::get_result() {
  size_t i = primes.find("P");
  while(i != string::npos){
    check_value(i);
    i = primes.find("P", i + 1);
  }
  return primes;
}

void Primefinder::check_value(size_t value) {
  for(size_t i = value + 1; i < primes.length(); i++) {
    if(check_prime(i, value))
      primes[i] = 'C';
  }
}

bool Primefinder::check_prime(size_t v1, size_t v2) {
  return v1 % v2 == 0;
}

size_t Primefinder::get_largest(size_t limit) {
  size_t value = limit;
  size_t flag = 0;
  while(--value > 1) {
    for(size_t i = 2; i < value; i++) {
      if(check_prime(value, i)) {
        flag = 1;
        break;
      }
    }
    if(flag == 0)
      return value;
    flag = 0;
  }
  return -1;
}
