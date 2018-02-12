#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include "word.h"
#include "dictionary.h"

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
			words[word.length() - 1].push_back(Word(word, trigrams)) ;
		}
	}
	infile.close();
}

bool Dictionary::contains(const string& word) const {
	return dictionary.count(word);
}

vector<string> Dictionary::get_suggestions(const string& word) const {
	vector<string> suggestions;

	add_trigram_suggestions(suggestions, word);
	rank_suggestions(suggestions, word);
	trim_suggestions(suggestions);

	return suggestions;
}
void Dictionary::add_trigram_suggestions(vector<string>& suggestions, const string& word) const{
	int word_length = word.length();
	if(word_length > 2 && word_length <= SIZE) {
		//create trigrams for misspelled word
		int nbrTrigrams = word_length - 2;
		std::vector<string> trigrams;
		for(int i = 0; i < nbrTrigrams; i++)
			trigrams.push_back(word.substr(i, 3));
		sort(trigrams.begin(), trigrams.end());
		//check if the word is the length of SIZE or not
		int m;
		int n;
		if(word_length == SIZE) {
			m = SIZE - 2;
			n = SIZE - 1;
		} else {
			m = word_length -2;
			n = word_length;
		}

		//get matching trigrams for the misspelled word from the lists with matching length
		unsigned int matches;
		for(int k = m ; k <= n; k++) {
			for(Word w: words[k]) {
				matches = w.get_matches(trigrams);
				if(matches >= trigrams.size() / 2) {
					suggestions.push_back(w.get_word());
				}
			}
		}
	}
}

void Dictionary::rank_suggestions(vector<string>& suggestions, const string& word) const {
	unsigned int row = word.length();
	if(row > 2 && row <= SIZE) {
		vector<std::pair<int,string>> ranking;
		for(string suggestion : suggestions) {
			unsigned int col = suggestion.length();
			int cost[SIZE+1][SIZE+1];
			//fill matrix
			cost[0][0] = 0;
			for(unsigned int i = 1; i <= row; ++i) cost[i][0] = i;
			for(unsigned int i = 1; i <= col; ++i) cost[0][i] = i;
			//calculate cost
			for(unsigned int i = 1; i <= row; ++i)
				for(unsigned int j = 1; j <= col; ++j)
					cost[i][j] = std::min({ cost[i - 1][j] + 1, cost[i][j - 1] + 1, cost[i - 1][j - 1] + (suggestion[j - 1] == word[i - 1] ? 0 : 1)});
			//fill vector according to cost matrix
			ranking.push_back(make_pair(cost[row][col], suggestion));
		}
		sort(ranking.begin(), ranking.end());
		suggestions.clear();
		//sort words
		for(auto pair: ranking) {
			suggestions.push_back(pair.second);
		}
	}
}
void Dictionary::trim_suggestions(vector<string>& suggestions) const {
	std::size_t size = suggestions.size() >= 5 ? 5 : suggestions.size();
	suggestions.resize(size);
}
