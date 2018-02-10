#include <iostream>
#include <string>
#include <algorithm>
#include "tagremover.h"

using std::size_t;
using std::cout;
using std::vector;

Tagremover::Tagremover(istream& is) {
  string line;
  while (std::getline(is, line)) {
    text += line;
  }
  edit_text();
}
Tagremover::Tagremover(string input) {
  text = input;
  edit_text();
}

void Tagremover::edit_text(){
  remove_tags();
  translate_tags();
}
//assuming people write two tags
void Tagremover::remove_tags(){
  size_t start = text.find("<");
  size_t end;
  while(start != string::npos) {
    end = text.find(">", start+1);
    text.replace(start - 1, end + 2 - start,"");
    start = text.find("<", end + 1);
  }
}

void Tagremover::translate_tags(){
  vector<string> ori_chars = {"&lt","&gt;","&nbsp;","&amp;"};
  vector<string> rep_chars = {"<",">","space","&"};
  for(size_t i = 0; i < ori_chars.size(); i++) {
    size_t start = text.find(ori_chars[i]);
    size_t end = ori_chars[i].length();
    while(start != string::npos) {
      text.replace(start, end, rep_chars[i]);
      start = text.find(ori_chars[i], start + 1 + end );
    }
  }
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
