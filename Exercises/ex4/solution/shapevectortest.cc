/*
 * shapevectortest.cc: check the identity of objects that are in 
 * a vector.
 * Corrected version. The problem with the original version was that
 * the vector was a vector of Shape objects, and when Square or 
 * Circle objects were copied to the vector they were _sliced_.
 * We must not copy objects, so we use a vector of (unique) pointers
 * instead.
 */

#include "shape.h"
#include "square.h"
#include "circle.h"

#include <memory>
#include <iostream>
#include <vector>
#include <random>
#include <ctime>

using namespace std;

int main() {
	/*
	 * A vector of Shape pointers (unique). 
	 */
	vector<unique_ptr<Shape>> shapes;
	const size_t NBR_SHAPES = 10;
	
	/*
	 * Store pointers to 10 squares and circles in the vector.
	 */
	default_random_engine re(time(0));
	bernoulli_distribution bd;
	for (int i = 0; i != NBR_SHAPES; ++i) {
		if (bd(re)) {
			shapes.push_back(unique_ptr<Shape>(new Square));
		} else {
			shapes.push_back(unique_ptr<Shape>(new Circle));
		}
	}
	
	/*
	 * Print the shapes.
	 */
	for (const auto& s : shapes) {
		s->print();
	}
}
