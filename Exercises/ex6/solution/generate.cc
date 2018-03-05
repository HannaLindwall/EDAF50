#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

template <typename T>
class SequenceGenerator {
public:
	SequenceGenerator(T istart = T(), T istep = 1) :
	    start(istart), step(istep) {}
	T operator()() {
		T temp = start;
		start += step;
		return temp;
	}
private:
	T start; // the start value of the sequence
	T step;  // the step
};

using namespace std;

int main() {
	vector<int> v(10); // allocate 10 elements
	
	/*
	 * Output: 10 15 20 25 30 35 40 45 50 55
	 */
	generate(v.begin(), v.end(), SequenceGenerator<int>(10, 5));
	copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	
	/*
	 * Output: 5 6 7 8 9 10 11 12 13 14
	 */
	generate(v.begin(), v.end(), SequenceGenerator<int>(5));
	copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	
	/*
	 * Output: 0 1 2 3 4 5 6 7 8 9
	 */
	generate(v.begin(), v.end(), SequenceGenerator<int>());
	copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	
	/*
	 * Output: abcd...xyz
	 */
	vector<char> chars('z' - 'a' + 1);
	generate(chars.begin(), chars.end(), SequenceGenerator<char>('a'));
	copy(chars.begin(), chars.end(), ostream_iterator<char>(cout));
	cout << endl;
}
