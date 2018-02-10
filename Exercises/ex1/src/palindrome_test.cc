#include <string>
#include <iostream>
#include "palindrome.h"

using std::cout;
using std::cin;
using std::string;
using std::endl;


void test_string() {
  string p1 = "anna";
  string p2 = "amanaplanacanalpanama";
  string np = "notapalindrome";
  Palindrome p;
  if (p.palindrome(np)) {
    cout << np << " is a palindrome";
  } else {
    cout << np << " is not a palindrome";
  }
}

void test_cin() {
  cout << "Type a word:" << endl;
  string word;
  cin >> word;
  Palindrome p;
  if (p.palindrome(word)) {
    cout << word << " is a palindrome";
  } else {
    cout << word << " is not a palindrome";
  }
}

int main() {
  test_string();
  cout << endl;
  test_cin();
}
