/*
 * class Point: a point with x and y coordinates.
 */

#ifndef POINT_H
#define POINT_H

class Point {
public:
	Point(double ix, double iy); // constructor
	double getX() const;	     // const: does not modify
	double getY() const;	     // the state of the object
	void move(double dx, double dy); // does modify, not const
private:
	double x;				     // member variables
	double y;
};							     // note semicolon

#endif
