#include "crypto.h"

#include <random>
#include <bitset>
using std::string;
using std::endl;

using namespace std;

string Crypto::encrypt(const string& text, unsigned int key) {
	string encrypted = "";
	std::default_random_engine generator(key);
	std::uniform_real_distribution<int> distribution(0, 256);
	for(unsigned int i = 0; i < text.length(); ++i) {
		unsigned char c = text[i];
		unsigned int digit = c - '0';
		unsigned myrand = distribution(generator);
		cout << "Character: " << c << endl;
		cout << "Character code: " << digit << endl;
		cout << "Random number: " << myrand % 256 << endl;
		digit += myrand % 256;
		c += digit - '0';
		cout << "Encrypted code: " << digit << endl;
		cout << "Encrypted character: " << c << endl;
		encrypted += c;
	}
	cout << text << key;
	return "";
}

string Crypto::decrypt(const string& crypt, unsigned int key) {
	return "";
}
