#include <iostream>
#include <iomanip> // for setw and setfill
#include <string>
#include <sstream>
#include <stdexcept>
#include <iomanip>
#include "date.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ostringstream;
using std::istringstream;
using std::setw;
using std::setfill;

template <typename T>
string toString(const T& obj) {
  ostringstream print;
  print << obj;
  return print.str();
}
template <typename T>
T string_cast(const string& obj) {
  istringstream caster(obj);
  T t;
  caster >> t;
  if(caster.fail()) {
    throw std::invalid_argument("Error");
  }
  return t;
}

void tostring_test() {
  try {
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
  catch (const std::invalid_argument& ia) {
	  std::cerr << "Invalid argument: " << ia.what() << '\n';
  }
}

int main () {
  tostring_test();
}
