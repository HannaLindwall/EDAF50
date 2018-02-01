#ifndef DICTIONARY_H
#define DICTIONARY_H
#define SIZE 25

#include <string>
#include <vector>
#include <unordered_set>
#include "word.h"
#include "preprocess.h"

using std::string;
using std::vector;

class Dictionary {
public:
	Dictionary();
	bool contains(const string& word) const;
	vector<string> get_suggestions(const string& word) const;

private:
	std::unordered_set<string> dictionary;
	vector<Word> words[SIZE];
	void add_trigram_suggestions(vector<string>& suggestions, const string& word) const;
	void rank_suggestions(vector<string>& suggestions, const string& word) const;
	void trim_suggestions(vector<string>& suggestions) const;
};

#endif
