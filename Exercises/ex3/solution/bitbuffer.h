#ifndef BIT_BUFFER_H
#define BIT_BUFFER_H

#include <iostream>

class BitBuffer {
public:
	BitBuffer(std::ostream& out);
	void put(bool b);
private:
	std::ostream& os;    // the output stream
	unsigned char byte;  // the buffer, 8 bits
	unsigned int n_bits; // the number of bits in the buffer
};

#endif
