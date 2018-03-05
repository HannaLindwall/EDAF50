/*
 * A base class Shape with two derived classes Square and Circle.
 * Corrected, the print() function is virtual.
 */

#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>

class Shape {
public:
	virtual void print() const {
		std::cout << "I'm a Shape" << std::endl;
	}
};

#endif
