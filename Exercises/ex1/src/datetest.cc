#include "date.h"

#include <iostream>

using namespace std;

int main() {
	// Check next() by creating an object describing today's date,
	// then print dates more than a month ahead.
	cout << "--- Today and more than a month ahead" << endl;
	Date d1;
	print(d1);
	cout << endl;
	for (int i = 1; i <= 35; ++i) {
		d1.next();
		print(d1);
		cout << endl;
	}
	
	// Check so next() functions correctly from one year to the next.
	cout << "--- New Year's Eve and the next day" << endl;
	Date d2(d1.get_year(), 12, 31);
	print(d2);
	cout << endl;
	
	d2.next();
	print(d2);
	cout << endl;
	
	// Check distance().
	Date d3(2015, 1, 1);
	Date d4(d3.get_year() + 1, 2, 2);
	cout << "--- Number of days between ";
	print(d3);
	cout << " and ";
	print(d4);
	cout << ", also reversed" << endl;
	cout << distance(d3, d4) << " (397)" << endl;
	cout << distance(d4, d3) << " (397)" << endl;
}

