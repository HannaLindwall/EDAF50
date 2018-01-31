#ifndef PREPROCESS_H
#define PREPROCESS_H

#include <string>
#include <vector>

class Preprocess {
public:
	Preprocess();
	std::vector<string> create_trigrams(const string& s, int nbrTrigrams);
private:
};

#endif
