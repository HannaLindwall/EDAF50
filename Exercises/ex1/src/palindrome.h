#include <string>
#include <iostream>

using std::cout;
using std::string;

class Palindrome {
public:
  Palindrome();
  bool palindrome(const string& word) const;
};
