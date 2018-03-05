/* 
 * Class SVector: an integer vector class with basic functionality
 * (get and set operations).
 */

#ifndef SVECTOR_H
#define SVECTOR_H

#include <cstdlib>

class SVector {
public:
	explicit SVector(size_t size); // a vector with 'size' elements
	SVector(const SVector& sv);    // copy constructor
	SVector& operator=(const SVector& rhs); // assignment operator
	~SVector();                    // deallocate the vector
	size_t size() const;           // number of elements
	int get(size_t i) const;       // number at index i
	void set(size_t i, int value); // change the number at index i
private:
	size_t n; // the size of the vector
	int* v;   // an array to hold the numbers
};

#endif
