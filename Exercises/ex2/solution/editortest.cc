#include "editor.h"

#include <iostream>

using namespace std;

int main() {
	Editor ed("...(...(...[...]...)...)...{...}...");
	cout << ed.find_left_par(15) << "\t(11)" << endl;
	cout << ed.find_left_par(19) << "\t(7)" << endl;
	cout << ed.find_left_par(23) << "\t(3)" << endl;
	cout << ed.find_left_par(31) << "\t(27)" << endl;
	cout << ed.find_left_par(32) << "\t(18446744073709551615)" << endl;
}
