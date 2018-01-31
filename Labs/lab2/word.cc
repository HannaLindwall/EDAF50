#include <string>
#include <vector>
#include <algorithm>    // std::find
#include "word.h"

using std::vector;
using std::string;

Word::Word(const string& w, const vector<string>& t):word(w),trigrams(t) {}

string Word::get_word() const {
	return word;
}

unsigned int Word::get_matches(const vector<string>& t) const {
	int counter = 0;
	for(string trigram : t) {
		if(std::find (trigrams.begin(), trigrams.end(), trigram) != trigrams.end()) {
			counter++;
		}
	}
	return counter;
}
