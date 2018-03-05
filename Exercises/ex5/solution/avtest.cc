#include "av.h"

#include <iostream>
#include <string>

using namespace std;

int main() {
	AV<string, int> months;
	months.insert({"january", 31});
	months.insert({"february", 28});
	months.insert({"march", 31});
	months.insert({"april", 30});
	months.insert({"may", 31});
	months.insert({"june", 30});
	months.insert({"july", 31});
	months.insert({"august", 31});
	months.insert({"september", 30});
	months.insert({"october", 31});
	months.insert({"november", 30});
	months.insert({"december", 31});
	for (const auto& p : months) {
		cout << p.first << " " << p.second << endl;
	}
	string m;
	while (cin >> m) {
		auto it = months.find(m);
		if (it != months.end()) {
			cout << it->first << " has " << it->second << " days" << endl;
		} else {
			cout << m << " is not a month" << endl;
		}
	}
}
