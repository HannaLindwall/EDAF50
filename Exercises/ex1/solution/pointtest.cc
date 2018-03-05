/*
 * Test the point class -- shows different ways of allocating
 * a Point object.
 */

#include "point.h"

#include <iostream>
#include <memory>

using namespace std;

/* 
 * Allocate on the stack -- the object is automatically destroyed
 * when the function is exited. This is the preferred way of
 * allocating.
 */
void f() {
	Point p1(1, 2);
	cout << p1.getX() << ", " << p1.getY() << endl;
	p1.move(5, 6);
	cout << p1.getX() << ", " << p1.getY() << endl;
}

/*
 * Allocate on the heap, using a safe pointer to keep track of the
 * object. The object is destroyed when the safe pointer goes out
 * of scope (when the function exits).
 */
void g() {
	unique_ptr<Point> p(new Point(1, 2));
	cout << p->getX() << ", " << p->getY() << endl;
	p->move(5, 6);
	cout << p->getX() << ", " << p->getY() << endl;
}

/*
 * Allocate on the heap, using a raw pointer to keep track of the
 * object. The object must be deleted before the function exits,
 * otherwise there's a memory leak. This kind of allocation should
 * normally not be used in application programs.
 */
void h() {
	Point* p = new Point(1, 2);
	cout << p->getX() << ", " << p->getY() << endl;
	p->move(5, 6);
	cout << p->getX() << ", " << p->getY() << endl;
	delete p;
}

int main() {
	f();
	cout << endl;
	g();
	cout << endl;
	h();
}
