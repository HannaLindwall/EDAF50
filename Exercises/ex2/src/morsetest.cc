#include "morsecode.h"

#include <iostream>
#include <string>

using namespace std;

int main() {
	MorseCode mc;
	string text = "a man, a plan, a canal - panama";
	cout << mc.encode(text) << endl;
	string code = ".... . .-.. .-.. --- .-- --- .-. .-.. -..";
	cout << mc.decode(code) << endl;
}
