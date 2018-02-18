#ifndef TAGREMOVER_H
#define TAGREMOVER_H
#include <iostream>
#include <string>
#include <string>
#include <vector>
#include <fstream>
using std::string;
using std::istream;
using std::ostream;

class Tagremover {
public:
	Tagremover(istream& is);
  Tagremover(string input);
	void edit_text();
  void print(ostream& os) const;
	string print_result(const string new_text) const;
private:
  void remove_tags();
  void translate_specialchars();
  string text;
};

#endif
