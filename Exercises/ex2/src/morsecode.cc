#include "morsecode.h"

using namespace std;

MorseCode::MorseCode() {
	ifstream is("morse.def");
	string line;
	while (std::getline(is, line)) {
		stringstream ss(line);
		char letter;
		string morse;
		ss >> letter;
		ss >> morse;
		alphabet[letter] = morse;
		morse_alphabet.push_back(morse);
	}
}

string MorseCode::encode(const string& text) const {
	ostringstream os;
	stringstream ss(text);
	string s;
	 while(ss >> s) {
	 	for(size_t i = 0; i < s.length(); i++) {
			auto morse = alphabet.find(s[i]);
	 		if(morse !=  alphabet.end()) {
	 			os << morse->second;
	 		}
		}
	 	os << " ";
	}
	return os.str();
}

string MorseCode::decode(const string& code) const {
	ostringstream os;
	stringstream ss(code);
	string s;
	string letter;
	while(ss >> s) {
		auto it = std::find(morse_alphabet.begin(), morse_alphabet.end(), s);
		if (it != morse_alphabet.end()) {
  		int index = std::distance(morse_alphabet.begin(), it);
			letter += index + 'a';
		}
	}
	os << letter;
	return os.str();
}
