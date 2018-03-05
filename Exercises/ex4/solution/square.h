#ifndef SQUARE_H
#define SQUARE_H

#include "shape.h"

#include <iostream>

class Square : public Shape {
public:
	virtual void print() const override {
		std::cout << "I'm a Square" << std::endl;
	}
};

#endif
