#include "editor.h"

#include <string>
#include <vector>
#include <iostream>

using namespace std;

string::size_type Editor::find_left_par(string::size_type pos) const {
	string::size_type left_pos;
	char right = text[pos];
	char left;
	switch(right) {
		case ')':left = '('; break;
		case ']':left = '['; break;
		case '}':left = '{'; break;
		default: return -1;
	}
	int between = 0;
	for(int i = pos - 1; i >= 0; --i) {
		if(text[i] == right) {
			between++;
		}

		if(between == 0 && text[i] == left) {
			return i;
		}

		if(text[i] == left) {
			between--;
		}
	}
	return -1;
}
