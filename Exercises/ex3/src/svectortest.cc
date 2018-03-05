#include "svector.h"

#include <iostream>

using namespace std;

/*
 * A function that prints all the elements in the SVector sv.
 */
void print(SVector sv) {
	size_t size = sv.size();
	for (size_t i = 0; i != size; ++i) {
		cout << sv.get(i) << " ";
	}
}

int main() {
	SVector v1(10);
	for (size_t i = 0; i != v1.size(); ++i) {
		v1.set(i, i + 1);
	}

	print(v1); // should print 1 2 3 4 5 6 7 8 9 10
	cout << endl;

	SVector v2(5);
	for (size_t i = 0; i != v2.size(); ++i) {
		v2.set(i, 10 * (i + 1));
	}
	print(v2); // should print 10 20 30 40 50
	cout << endl;

	print(v1); // should print 1 2 3 4 5 6 7 8 9 10
	cout << endl;
	SVector copy(10);
	copy = v1;
	print(copy); // should print 1 2 3 4 5 6 7 8 9 10
	cout << endl;
}
