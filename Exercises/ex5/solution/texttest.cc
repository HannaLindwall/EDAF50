#include "text.h"
#include "textiterator.h"

#include <iostream>

using namespace std;

int main() {
	Text t;
	t.addLine("Line 1 ...");
	t.addLine("This is the second line.");
	t.addLine("And this is the last line.");
	
	for (Text::iterator it = t.begin(); it != t.end(); ++it) {
		if (*it == ' ') {
			*it = 'X';
		}
		cout << *it;
	}
	cout << endl;
}
