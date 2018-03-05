#include "morsecode.h"

#include <fstream>
#include <sstream>

using namespace std;

MorseCode::MorseCode() {
	ifstream in("morse.def");
	char ch;
	string code;
	while (in >> ch >> code) {
		table[ch - 'a'] = code;
	}
	in.close();
}

string MorseCode::encode(const string& text) const {
	string result;
	for (char ch : text) {
		if (ch >= 'a' && ch <= 'z') {
			result += table[ch - 'a'] + " ";
		}
	}
	return result;
}

string MorseCode::decode(const string& code) const {
	istringstream iss(code);
	string s;
	string result;
	while (iss >> s) {
		int i = 0;
		while (i != 26 && table[i] != s) {
			++i;
		}
		result += (i != 26) ? static_cast<char>(i + 'a') : '?';
	}
	return result;
}
