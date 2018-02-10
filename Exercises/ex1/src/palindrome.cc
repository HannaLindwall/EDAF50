#include <string>
#include <iostream>
#include "palindrome.h"

using std::cout;
using std::string;
using std::endl;

Palindrome::Palindrome() {}

bool Palindrome::palindrome(const string& word) const {
  int i = 0;
  int j = word.length() -1;
  while(i < j) {
    cout << word[i] << " " << word[j] << endl;
    if(word[i] != word[j])
      return false;
    i++;
    j--;
  }
  return true;
}
