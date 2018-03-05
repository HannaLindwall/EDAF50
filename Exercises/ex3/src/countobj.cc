/*
 * countobj.cc: count creation and destruction of objects. One class and
 * several functions, all in this file.
 */

#include <iostream>
#include <string>

class Counted {
public:
	Counted();
	~Counted();
	static int getNbrObj();
private:
	static int nbrObj;
};

int Counted::nbrObj = 0;

Counted::Counted() {
	nbrObj++;
}

Counted::~Counted() {
	nbrObj--;
}

int Counted::getNbrObj() {
	return nbrObj;
}
//c is destroyed after f is done, pc is deleted
void f() {
	Counted c;
	Counted* pc = new Counted;
	delete pc;
}
//the copy c2 doesn't increment the counter, but when destroyed it decreases the counter.
void g() {
	Counted c1;
	Counted c2 = c1;
}
//the copy c1 and c2 are both objects which increases the counter, and are then destroyed. The counter stays the same.
void h() {
	Counted c1;
	Counted c2;
	c2 = c1;
}

using namespace std;

void print_nbr_objects(const string& msg) {
	cout << msg << " -- number of objects: "
	     << Counted::getNbrObj() << endl;
}

int main() {
	print_nbr_objects("Program start, before f()");
	f();

	print_nbr_objects("After f(), before g()    ");
	g();

	print_nbr_objects("After g(), before h()    ");
	h();

	print_nbr_objects("After h(), program end   ");
}
