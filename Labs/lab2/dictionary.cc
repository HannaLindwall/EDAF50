#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <math>
#include "word.h"
#include "dictionary.h"
#include "preprocess.h"

using std::string;
using std::vector;

Dictionary::Dictionary() {
	std::ifstream infile("words.txt");
  std::string line;
	while (std::getline(infile, line)) {
		std::stringstream sstm(line);
		string word;
		sstm >> word;
		if(word.length() > 0 && word.length() <= SIZE) {
			dictionary.insert(word);
			int size;
			sstm >> size;
			vector<string> trigrams;
			string trigram;
			while(sstm >> trigram) {
				trigrams.push_back(trigram);
			}
			words[word.length() - 1].push_back(Word w(word, trigrams)) ;
		}
	}
}

bool Dictionary::contains(const string& word) const {
	auto got = dictionary.find(word);
	if(got == dictionary.end()) {
		return false;
	}
	return true;
}

vector<string> Dictionary::get_suggestions(const string& word) const {
	vector<string> suggestions;

	add_trigram_suggestions(suggestions, word);
	rank_suggestions(suggestions, word);
	trim_suggestions(suggestions);

	return suggestions;
}
add_trigram_suggestions(vector<string>& suggestions, const string& word) const{
	word_length = word.length();
	if(word_length > 2 && word_length <= SIZE) {

		int nbrTrigrams = word_length - 2;
		Word input(word, create_trigrams(word, nbrTrigrams));

		vector<Word> list1;
		vector<Word> list2;
		vector<Word> common_lenght;
		if(word_length == SIZE) {
			list1 = words[SIZE-2];
			list2 = words[SIZE-1];
			common_lenght = list1.insert(list1.end(), list2.begin(), list2.end());
		} else {
			list1 = words[word_length-2];
			list2 = words[word_length-1];
			list1.insert(list1.end(), list2.begin(), list2.end());
			common_lenght = list1;
			common_lenght.insert(common_lenght.end(), words[word_length].begin(), words[word_length].end())
		}

		int matches;
		for(Word w: common_lenght) {
			matches = input.get_matches(w.trigrams);
			if(matches >= ceil(input.trigrams.size() / 2)) {
				suggestions.push_back(w.word);
			}
		}
	}
	return suggestions;
}
vector<string> rank_suggestions(vector<string>& suggestions, const string& word) const {
	int row = word.length();
	if(row > 2) {
		vector<string> ranking[SIZE];
		row += 1;
		for(string s : suggestions) {
			int col = s.length();
			int cost[row][col];
			//fill matrix
			cost[0][0] = 0;
			for(unsigned int i = 1; i <= row; ++i) d[i][0] = i;
			for(unsigned int i = 1; i <= col; ++i) d[0][i] = i;
			//calculate cost
			for(int i = 1; i <= row; i++) {
				for(int j = 1; j <= col; j++) {
					cost[i][j] = std::min({ cost[i - 1][j] + 1, cost[i][j - 1] + 1, cost[i - 1][j - 1] + (s[i - 1] == word[j - 1] ? 0 : 1)});
				}
			}
			//fill vector according to cost matrix
			ranking[cost[row][col]].push_back(s);
		}
		suggestions.clear();
		for(string s: ranking[k]) {
			for() {

			}

			if(!ranking[k].empty()){
				sort(ranking[k].begin(), ranking[k].end());
				suggestions.push_back(s);
			}
		}

	}
	return suggestions;
}
trim_suggestions(vector<string>& suggestions) const {
	return suggestions = vector<string>(suggestions.begin(), suggestions.begin() + 5);
}
