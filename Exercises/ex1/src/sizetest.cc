/*
 * Explain the output of the following program.
 */

#include "point.h"

#include <iostream>

using namespace std;

int main() {
	Point p(1, 2);
	cout << "sizeof(p)      = " << sizeof(p) << endl;
	
	Point* pp = new Point(1, 2);
	cout << "sizeof(pp)     = " << sizeof(pp) << endl;
	cout << "sizeof(*pp)    = " << sizeof(*pp) << endl;
	
	delete pp;
}
