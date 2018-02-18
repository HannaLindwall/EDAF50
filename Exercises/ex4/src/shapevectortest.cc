/*
 * shapevectortest.cc: check the identity of objects that are in
 * a vector.
 */

#include "shape.h"
#include "square.h"
#include "circle.h"

#include <iostream>
#include <vector>
#include <random>
#include <ctime>

using namespace std;

int main() {
	/*
	 * A vector of Shape objects
	 */
	vector<Shape*> shapes;
	const size_t NBR_SHAPES = 10;

	/*
	 * Store 10 squares and circles in the vector.
	 */
	default_random_engine re(time(0));
	bernoulli_distribution bd;
	for (int i = 0; i != NBR_SHAPES; ++i) {
		if (bd(re)) {
			shapes.push_back(new Square());
		} else {
			shapes.push_back(new Circle());
		}
	}

	/*
	 * Print the shapes.
	 */
	for (const auto& s : shapes) {
		s->print();
	}
}
