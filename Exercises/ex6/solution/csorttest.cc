#include <iterator>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <string>
#include <iostream>
#include <random>
#include <chrono>
#include <ctime>
#include <iomanip>

template <typename Iterator>
// Iterator is a model of ForwardIterator.
// Sort integral values in the range [first, last) with Counting sort.
// The difference between the largest element and the smallest
// element should not be too large.
void csort(Iterator first, Iterator last) {
	if (first == last) {
		return;
	}
	auto minmax = std::minmax_element(first, last);
	auto min = *minmax.first;
	auto max = *minmax.second;
	size_t rangeSize = max - min + 1;
	std::vector<unsigned> nbrElements(rangeSize);
	for (Iterator it = first; it != last; ++it) {
		nbrElements[*it - min]++;
	}
	for (std::vector<unsigned>::size_type i = 0; i != nbrElements.size(); ++i) {
		for (size_t j = 0; j != nbrElements[i]; ++j) {
			*first++ = i + min;
		}
	}
}

template <typename Iterator>
// Iterator is a model of InputIterator.
// Prints a message, then the values in the range [first, last).
void debug_print(Iterator first, Iterator last, const std::string& message) {
	using namespace std;
	cout << endl << message << endl;
	copy(first, last, ostream_iterator<decltype(*first)>(cout, " "));
	cout << endl << endl;
}

using namespace std;
using namespace std::chrono;

int main() {
	size_t nbrElements;
	cout << "Number of elements: ";
	cin >> nbrElements;
	
	int minElem, maxElem;
	cout << "Min and max element: ";
	cin >> minElem >> maxElem;
	
	char ch;
	cout << "Print for debug (y/n)? ";
	cin >> ch;
	bool print = ch == 'y';
	
	/*
	 * Fill the sequence with random ints in the range
	 * [minElem, maxElem].
	 */
	default_random_engine re(time(0));
	uniform_int_distribution<int> rand(minElem, maxElem);
	vector<int> v;
	for (size_t i = 0; i != nbrElements; ++i) {
		v.push_back(rand(re));
	}
	auto vCopy = v;
	
	if (print) {
		debug_print(v.begin(), v.end(), "Unsorted sequence:");
	}
	
	auto startTime = high_resolution_clock::now();
	csort(v.begin(), v.end());
	double elapsedTime =
	    duration_cast<milliseconds>(high_resolution_clock::now() - startTime).count();
	cout << "csort() time (seconds):	 "
		 << setiosflags(ios::fixed) << setprecision(3) << elapsedTime / 1000 << endl;
	
	if (print) {
		debug_print(v.begin(), v.end(), "Sequence sorted with csort():");
	}
	
	startTime = high_resolution_clock::now();
	sort(vCopy.begin(), vCopy.end());
	elapsedTime =
	    duration_cast<milliseconds>(high_resolution_clock::now() - startTime).count();
	cout << "std::sort() time (seconds): "
		<< setiosflags(ios::fixed) << setprecision(3) << elapsedTime / 1000 << endl;
	
	if (print) {
		debug_print(vCopy.begin(), vCopy.end(),  "Sequence sorted with std::sort():");
	}
}
