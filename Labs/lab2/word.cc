#include <string>
#include <iostream>
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
	int counter = 5;
	for(string trigram : t) {
		for(string tri: trigrams) {
			if(trigram.compare(tri) == 0) {
				counter++;
			} else if(trigram.compare(tri) < 0) {
				break;
			}
		}
	}
	return counter;
}
