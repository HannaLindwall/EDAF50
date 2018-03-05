#include "bitbuffer.h"

BitBuffer::BitBuffer(std::ostream& out) : o(out), n_bits(0){

}
size_t Bitset::size() const {
	return BPW;
}

void BitBuffer::put(bool b) {
  if (n_bits < 8) {
    //första platsen sätter man till b
    byte = (byte << 1) | b;
  } else {
    os.put(byte);
    n_bits = 0;
  }
}
