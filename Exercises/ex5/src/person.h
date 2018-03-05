#ifndef PERSON_H
#define PERSON_H

#include <string>

/*
 * A person with a name and a phone number.
 */
class Person {
public:
	Person(const std::string& n, const std::string& p) :
	name(n), phone(p) {}
	std::string get_name() const { return name; }
	std::string get_phone() const { return phone; }
private:
	std::string name;
	std::string phone;
};
bool operator<(const Person& p1, const Person& p2);
std::ostream& operator<<(std::ostream& os, const Person& p);

#endif
