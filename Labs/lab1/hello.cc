#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <bitset>
#include <stdexcept>
#include <map>

using namespace std;
// int i = 42;
// int b = 1;
std::function<int(int)> incr(int b){
  return [=](int a) { return a + b; };
}
// template <typename T> T fobj(T);
// template <typename T> T fref(const T&);

string method1() { cout << "hej" << endl; return "hej"; }
void method2() { cout << "hej2" << endl; }
typedef string (*meth1)();
typedef void (*meth2)();

struct Foo{
virtual void print() const {std::cout << "Foo" << std::endl;}
};
struct Bar : Foo {
virtual void print() const override {std::cout << "Bar" << std::endl;}
};
struct Qux : Bar {
virtual void print() const override {std::cout << "Qux" << std::endl;}
};
void print1(const Foo* f)
{
f->print();
}
void print2(const Foo& f)
{
f.print();
}
void print3(Foo f)
{
f.print();
}

int main()
{
    cout << "Hello World" << endl;
    // int i = 1;
    // int j = ::i;
    // cout << j << endl;
    // int j = 5.2;
    // double slope = static_cast<double>(j)/i;
    // int *p = &i;
    // int *n = 0;
    // if(p)
    //   cout << p << " " << i << endl;
    // if(*p)
    //   cout << *p << " " << i << endl;
    // if(n)
    //   cout << p << " " << i << endl;
    // unsigned scores[11] = {};
    // unsigned grade;
    // while(cin >> grade) {
    //   if(grade <= 100) {
    //     cout << scores[grade/10] << endl;
    //     scores[grade/10]++;
    //     cout << scores[grade/10] << endl;
    //   }
    //   cout << endl;
    // }
    // int i = 100, j = 0;
    // for(int i = 0; i != 10; ++i)
    //   j += 1;
    // cout << i << endl;
    // cout << j << endl;
    // int val = 1;
    // vector<int> v = {1,2,4, 1};
    // auto it = std::remove_if(v.begin(), v.end(), [val] (const int& i){ return i==val; });
    // if(it != v.end()) {
    //   cout << *it++ << endl; // skriver ut 1
    //   cout << *it << endl; // skriver ut 2
    //   cout << *it++ << endl; // skriver ut 1
    //   cout << *it << endl; // skriver ut 2
    // }
    // int a[10];
    // fobj(a);
    // fref(&a);
    // unsigned int v = 1;
    // vector<unsigned char> val;
    // val.push_back(v);
    // char c;
    // string s;
    // getline(cin, s);
    // while(cin >> c)
    //   cout << c << " ";
    // auto f2 = incr(2);
    // cout << f2(10) << endl;
    // auto f3 = incr(5);
    // cout << f3(10) << endl;
    // vector<std::bitset<80>> vec;

    // Foo* a =  new Bar;
    // Bar& b = *new Qux;
    // Bar  c = *new Qux;
    // print1(a);
    // print1(&b);
    // print1(&c);
    // std::cout << std::endl;
    // print2(*a);
    // print2(b);
    // print2(c);
    // std::cout << std::endl;
    // print3(*a);
    // print3(b);
    // print3(c);
    // std::cout << std::endl;
    // unsigned int a;
    // try {
    //   while(cin >> a)
    //     cout << a;
    // } catch (std::exception& e) {
    //   cout << "nope";
    // }
    map<int, meth1> map1;
    map<int, meth2> map2;
    map1[1] = &method1;
    map1[1]();
    map2[1] = &method2;
    map2[1]();
    return 0;
}
