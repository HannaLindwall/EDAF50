#ifndef PREPROCESS_H
#define PREPROCESS_H

#include <string>
#include <vector>

class Preprocess {
public:
	Preprocess();
	std::vector<std::string> create_trigrams(const std::string& s, int nbrTrigrams) const;
private:
};

#endif
