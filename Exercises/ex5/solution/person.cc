#include "person.h"

#include <iostream>

std::ostream& operator<<(std::ostream& os, const Person& p) {
	return os << p.get_name() << " " << p.get_phone();
}
