#include "person.h"

#include <iostream>
#include <string>

std::ostream& operator<<(std::ostream& os, const Person& p) {
	return os << p.get_name() << " " << p.get_phone();
}
bool operator<(const Person& p1, const Person& p2) {
	std::string name1 = p1.get_name();
	std::string name2 = p2.get_name();
	std::string phone1 = p1.get_phone();
	std::string phone2 = p2.get_phone();

	if(name1 == name2) {
		std::cout << "hej" << std::endl;
		return phone1 < phone2;
	} else {
		return name1 < name2;
	}

	return false;
}
