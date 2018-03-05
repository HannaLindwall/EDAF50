/*
 * Explain the output of the following program.
 */

#include "point.h"

#include <iostream>

using namespace std;

int main() {
	Point p(1, 2);
	/*
	 * A point object contains 2 double's, so sizeof(d) == 2 sizeof(double).
	 */
	cout << "sizeof(double) = " << sizeof(double) << endl;
	cout << "sizeof(p)      = " << sizeof(p) << endl;
	
	Point* pp = new Point(1, 2);
	/*
	 * pp is a pointer, so sizeof(pp) is 4 bytes (on a 32-bit machine)
	 * or 8 bytes (on a 64-bit machine).
	 */
	cout << "sizeof(pp)     = " << sizeof(pp) << endl;
	
	/*
	 * pp points at a point object, *pp _is_ a point object.
	 */
	cout << "sizeof(*pp)    = " << sizeof(*pp) << endl;
	
	delete pp;
}
