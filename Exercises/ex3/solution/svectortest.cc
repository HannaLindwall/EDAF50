/*
 * The comments in main() describe what happens in the original
 * version of the program. There are two solutions to the problem:
 * 1) avoid copying by passing the parameter to print by constant
 *	  reference (const SVector& sv), or
 * 2) write a copy constructor in SVector (see svector.h). If you
 *	  do this, you should also write an assignment operator.
 * In this case, we should naturally have passed the parameter by
 * constant reference -- we don't need a copy of the vector just
 * to print it. But even if we do that, there may be other 
 * reasons that we should allow vectors to be copied, so we 
 * choose the second solution.	
 */
 
#include "svector.h"

#include <iostream>

using namespace std;

/*
 * A function that prints all the elements in the SVector sv.
 */
void print(SVector sv) {
	size_t size = sv.size();
	for (size_t i = 0; i != size; ++i) {
		cout << sv.get(i) << " ";
	}
}

int main() {
	/*
	 * This part is ok. We create a vector with 10 elements and
	 * assign values to the elements.
	 */
	SVector v1(10);
	for (size_t i = 0; i != v1.size(); ++i) {
		v1.set(i, i + 1);
	}
	
	/* Then we print the vector, and we're in trouble. The vector 
	 * is called by value, and we haven't defined a copy constructor,
	 * so the default copy constructor is used. It performs memberwise
	 * copying of v1 to the formal parameter sv. When print is exited, 
	 * sv is deallocated, the destructor is called, and sv.v is
	 * deleted. But since the default copy constructor was used, sv.v
	 * is the same as v1.v, and v1.v now points to unallocated memory.
	 */
	print(v1); // should print 1 2 3 4 5 6 7 8 9 10
	/* 
	 * So here, v1.v points at unallocated memory that may be used
	 * on the next call to new.
	 */
	cout << endl;
	
	/*
	 * We allocate a new vector, which may (or may not, it depends on
	 * the implementation of new and delete) use the same memory as
	 * v1.v. v2 is allocated correctly, but print(v2) has the same
	 * problems as print(v1).
	 */
	SVector v2(5);
	for (size_t i = 0; i != v2.size(); ++i) {
		v2.set(i, 10 * (i + 1));
	}
	print(v2); // should print 10 20 30 40 50
	cout << endl;
	
	/*
	 * Here, anything may happen. v1.v points somewhere, v2.v may have
	 * used the same memory, the results are undefined.
	 */
	print(v1); // should print 1 2 3 4 5 6 7 8 9 10
	cout << endl;
}
