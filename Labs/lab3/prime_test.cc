#include <iostream>
#include <string>
#include <fstream>
#include "primefinder.h"

using std::string;
using std::vector;
using std::cout;

void test_primes() {

  string correct = "CCPPCPCPCCCPCPCCCPCPCCCPCCCCCPCPCCCC";

  size_t m = 35;
  Primefinder finder(m);

  string result = finder.get_result();
  if(correct == result){
    cout << "correct" << "\n";
  } else {
    cout << "fail" << "\n";
    cout << correct << "\n\n";
    cout << result << "\n";
  }
}

void print_twohundred(size_t m) {
  Primefinder finder(m);
  string result = finder.get_result();
  size_t i = result.find("P");
  while(i != string::npos) {
    cout << i << "\n";
    i = result.find("P", i + 1);
  }
}

void test_largest_prime(size_t limit) {
  size_t m = 5;
  Primefinder finder(m);
  size_t correct = 99991;
  size_t result = finder.get_largest(limit);
  if(correct == result){
    cout << "correct largest: " << result << "\n";
  } else {
    cout << "failed largest" << "\n";
    cout << result << "\n";
  }
}

int main() {
  test_primes();
  size_t m = 200;
  print_twohundred(m);
  size_t limit = 100000;
  test_largest_prime(limit);
}
