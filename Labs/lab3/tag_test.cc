#include <iostream>
#include <string>
#include <fstream>
#include "tagremover.h"

using std::string;
using std::vector;
using std::cout;
using std::cin;

void testRemoving(){
  string test = "Hejsan <hej>";
  string correct = "Hejsan";
  Tagremover tester(test);
  tester.print(cout);
  cout << tester.print_result(correct) << "remove tags" << "\n";

}
void testTranslating() {
  string test = "hej &amp; &lt &gt; &nbsp;";
  string correct = "hej & < > space";
  Tagremover tester(test);
  tester.print(cout);
  cout << tester.print_result(correct) << "translate special chars" << "\n";
}

int main() {
  testRemoving();
  testTranslating();
  Tagremover tester(cin);
}
