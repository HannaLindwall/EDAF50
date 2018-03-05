#include "bitbuffer.h"

#include <iostream>

using namespace std;

int main() {
	BitBuffer buf(cout);
	int n;
	while (cin >> n) {
		buf.put(n != 0);
	}
	cout << endl;
}
