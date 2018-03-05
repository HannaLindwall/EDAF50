#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <regex>
#include <iterator>

using std::istringstream;
using std::string;
using std::pair;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::size_t;


void print(vector<pair<string, int>>& ordered) {
  int occurrance = ordered[0].second;
  int i = 0;
  while(ordered[i].second == occurrance) {
    cout << "word: " << ordered[i].first << " occurred: " << ordered[i].second << endl;
    i++;
  }
}

bool update(const string& word, vector<pair<string, int>>& ordered) {
  auto it = std::remove_if(ordered.begin(), ordered.end(),
    [word] (const pair<string, int>& element) { return word == element.first;});
  if(it != ordered.end()) {
    int new_score = it->second + 1;
  //   ordered.insert(upper_bound(ordered.begin(), ordered.end(), make_pair(word, it->second++),
  //     [word](pair<string, int>& element){ return element.second < it->second; }));
    ordered.erase(it, ordered.end());
    for(size_t i = 0; i < ordered.size() ; ++i) {
      if(ordered[i].second < new_score ) {
        ordered.insert(ordered.begin() + i, make_pair(word, new_score));
        return true;
      }
    }
  }
  return false;
}

bool manage_word(const string& word, vector<pair<string, int>>& ordered) {
  auto it = std::find_if(ordered.begin(), ordered.end(),
    [word] (const pair<string, int>& element) { return element.first == word; });
  if(it != ordered.end()) {
    return update(word, ordered);
  } else {
    ordered.emplace_back(word, 1);
    return true;
  }
  return false;
}

int main() {
  vector<pair<string, int>> words_order;
  string line;
  while (std::getline(cin, line)) {
    istringstream ss(line);
    string word;
    while(ss >> word) {
      manage_word(word, words_order)
    }
  }
  print(words_order);
}
