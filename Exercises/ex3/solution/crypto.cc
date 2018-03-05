#include "crypto.h"

#include <string>
#include <random>

using namespace std;

string Crypto::encrypt(const string& text, unsigned int key) {
	default_random_engine e(key);
	uniform_int_distribution<unsigned> u(0, 255);
	string result(text.size(), ' ');
	for (string::size_type i = 0; i != text.size(); ++i) {
		result[i] = (text[i] + u(e)) % 256;
	}
	return result;
}

string Crypto::decrypt(const string& crypt, unsigned int key) {
	default_random_engine e(key);
	uniform_int_distribution<unsigned> u(0, 255);
	string result(crypt.size(), ' ');
	for (string::size_type i = 0; i != crypt.size(); ++i) {
		result[i] = (crypt[i] - u(e)) % 256;
	}
	return result;
}
