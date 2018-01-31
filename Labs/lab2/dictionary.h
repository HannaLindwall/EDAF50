#ifndef DICTIONARY_H
#define DICTIONARY_H
#define SIZE 25

#include <string>
#include <vector>
#include <unordered_set>

using std::string;
using std::vector;

class Dictionary {
public:
	Dictionary();
	bool contains(const string& word) const;
	vector<string> get_suggestions(const string& word) const;

private:
	unordered_set<string> dictionary;
	vector<Word> words[SIZE];
	add_trigram_suggestions(vector<string>& suggestions, const string& word) const;
	rank_suggestions(vector<string>& suggestions, const string& word) const;
	trim_suggestions(vector<string>& suggestions) const;
};

#endif
