/*
 * A BitsetIterator is an iterator for Bitsets.
 * Postfix ++, ==, and -> are not implemented.
 */

#ifndef BITSET_ITERATOR_H
#define BITSET_ITERATOR_H

#include "bitreference.h"
#include <iterator>
#include <iostream>
using std::cout;
using std::endl;

class BitsetIterator : public std::iterator<std::forward_iterator_tag, bool> {
public:
	BitsetIterator(Bitset::BitStorage* pb, std::size_t p) : ref(pb, p) {}

	bool operator!=(const BitsetIterator& bsi) const {
		return ref.pos != bsi.ref.pos;
	}

	BitsetIterator& operator++() {
		ref.pos++;
		return *this;
	}

	BitReference operator*() {
		return ref;
	}

	BitsetIterator& operator=(const BitsetIterator& rhs) {
		ref.p_bits = rhs.ref.p_bits;
		ref.pos = rhs.ref.pos;
		return *this;
	}
private:
	BitReference ref;
};

#endif
