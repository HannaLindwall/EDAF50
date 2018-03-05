/*
 * Class SVector: implementation.
 */

#include "svector.h"

SVector::SVector(size_t size) : n(size), v(new int[n]) {}
//create copy constructor, which actally changes the values of vector
SVector::SVector(const SVector& sv) : n(sv.n), v(new int[sv.n]){
	for(size_t i = 0; i < n; ++i) {
		v[i] = sv.v[i];
	}
}
SVector::~SVector() {
	delete[] v;
}
SVector& SVector::operator=(const SVector& copy) {
	if (this == &copy) {
		return *this;
	}
	delete[] v;
	n = copy.n;
	v = new int[copy.n];
	for(size_t i = 0; i < copy.n; ++i) {
		v[i] = copy.v[i];
	}
	return *this;
}
size_t SVector::size() const {
	return n;
}

int SVector::get(size_t i) const {
	return v[i];
}
void SVector::set(size_t i, int value) {
	v[i] = value;
}
