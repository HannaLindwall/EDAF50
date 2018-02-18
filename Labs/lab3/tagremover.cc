#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <regex>
#include "tagremover.h"

using std::size_t;
using std::cout;
using std::vector;

Tagremover::Tagremover(istream& is) {
  string line;
  while (std::getline(is, line)) {
    text += line;
    text += "\n";
  }
  edit_text();
}
Tagremover::Tagremover(string input) {
  text = input;
  edit_text();
}

void Tagremover::edit_text(){
  remove_tags();
  translate_specialchars();
}
//assuming people write two tags
void Tagremover::remove_tags(){
  std::regex e (" <[^>]*>");
  text = std::regex_replace(text, e, "");
}
//map istället, regex går igenom filen en gång
void Tagremover::translate_specialchars(){
  std::regex e("&amp");
  text = std::regex_replace(text, e, "&");
  e = {"&nbsp"};
  text = std::regex_replace(text, e, " ");
  e = {"&gt"};
  text = std::regex_replace(text, e, ">");
  e = {"&lt"};
  text = std::regex_replace(text, e, "<");
}

void Tagremover::print(ostream& os) const {
  os << text << "\n";
}

string Tagremover::print_result(const string input) const{
  string message;
  if(text == input) {
    message = "succeeded to: ";
  } else {
    message = "failed to: ";
  }
  return message;
}
