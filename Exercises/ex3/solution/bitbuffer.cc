#include "bitbuffer.h"

#include <iostream>

BitBuffer::BitBuffer(std::ostream& out) : os(out), n_bits(0) {}

void BitBuffer::put(bool b) {
	byte = (byte << 1) | b;
	if (++n_bits == 8) {
		os.put(byte);
		n_bits = 0;
	}
}
