#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
using std::cout;
using std::endl;
using std::string;

std::vector<string> create_trigrams(const string& line, int nbrTrigrams) {
  std::vector<string> trigrams;
  for(int i = 0; i < nbrTrigrams; i++) {
    trigrams.push_back(line.substr(i, 3));
  }
  sort(trigrams.begin(), trigrams.end());
  return trigrams;
}

int main()  {
  std::ifstream infile("words");
  std::string line;

  std::ofstream wordfile;
  wordfile.open("words.txt");
  while (std::getline(infile, line)) {
    std::transform(line.begin(), line.end(), line.begin(), ::tolower);
    wordfile << line << " ";
    int nbrTrigrams = line.length() - 2;
    if(nbrTrigrams < 1) {
      wordfile << " 0 ";
    } else {
      wordfile << nbrTrigrams << " ";
      std::vector<string> trigrams = create_trigrams(line, nbrTrigrams);
      for(string item : trigrams) {
        wordfile << item << " ";
      }
    }
    wordfile << endl;
  }
  wordfile.close();
}
