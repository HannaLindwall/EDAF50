#include <iostream>
#include <iomanip> // for setw and setfill
#include <string>
#include <sstream>
#include "date.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ostringstream;
using std::setw;
using std::setfill;

template <typename T>
string toString(const T& obj) {
  std::ostringstream print;
  print << obj;
  return print.str();
}
template <typename T>
T string_cast(const string& obj) {
  std::istringstream caster(obj);
  T t;
  caster >> t;
  return t;
}

void tostring_test() {
  double d = string_cast<double>("1.234");
  Date today = string_cast<Date>("2018-02-09");
  string sd = toString(d);
  string st = toString(today);
  cout << sd << endl;
  if(d == std::stod(sd)) {
    cout << "int toString succeeded" << endl;
  } else {
      cout << "int toString failed" << endl;
  }
  int text = today.getYear();
  ostringstream convert;   // stream used for the conversion
  convert << setw(4) << setfill('0') << text << "-";
  text = today.getMonth();
  convert << setw(2) << setfill('0') << text << "-";
  text = today.getDay();
  convert << setw(2) << setfill('0') << text << "\n";
  string date = convert.str();
  if(date == st) {
    cout << "Date toString succeeded" << endl;
  } else {
    cout << "Date toString failed" << endl;
  }
}

int main () {
  tostring_test();
}
