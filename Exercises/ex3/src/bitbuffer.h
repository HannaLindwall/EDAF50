#ifndef BIT_BUFFER_H
#define BIT_BUFFER_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <bitset>
using std::cout;
using std::endl;
using std::ostringstream;
using std::istringstream;
using std::string;
using std::vector;
using std::bitset;

class BitBuffer {
public:
	BitBuffer(std::ostream& out);
	void put(bool b);
private:
	unsigned char byte;
	unsigned int n_bits;
	std::ostream& o;
};

#endif
