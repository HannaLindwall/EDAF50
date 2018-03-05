#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

using count_type = map<string, size_t>;
using count_iter_type = map<string, size_t>::const_iterator;

void count_words(istream& in, count_type& count) {
	string word;
	while (in >> word) {
		++count[word];
	}
}

void print_common(const count_type& count, size_t n) {
	vector<count_iter_type> iters;
	for (count_iter_type it = count.begin(); it != count.end(); ++it) {
		iters.push_back(it);
	}
	auto sorted_end = iters.begin() + min(n, iters.size());
	partial_sort(iters.begin(), sorted_end, iters.end(),
			[](count_iter_type it1, count_iter_type it2)
				 { return it1->second > it2->second; });
	for (auto vit = iters.begin(); vit != sorted_end; ++vit) {
		cout << (*vit)->first << "\t" << (*vit)->second << endl;
	}
}

int main(int argc, const char** argv) {
	count_type count;
	for (int i = 1; i < argc; ++i) {
		ifstream in(argv[i]);
		if (!in) {
			cerr << "Cannot open: " << argv[i] << endl;
		} else {
			count_words(in, count);
			in.close();
		}
	}
	print_common(count, 20);
}
