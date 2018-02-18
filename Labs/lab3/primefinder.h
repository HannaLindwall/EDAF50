#ifndef PRIMEFINDER_H
#define PRIMEFINDER_H
#include <iostream>
#include <string>
#include <string>
#include <vector>
#include <fstream>
using std::string;
using std::istream;
using std::size_t;

class Primefinder {
public:
	Primefinder(size_t m);
  string get_result();
  size_t get_largest(size_t limit);
private:
  void check_value(const size_t value);
  bool check_prime(const size_t v1, const size_t v2);
  string primes;
};

#endif
