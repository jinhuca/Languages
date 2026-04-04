// C170304_initializer_list_constructors.cpp 
#include <initializer_list>
#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <map>

using std::initializer_list;
using std::string;
using std::cout;
using std::vector;
using std::list;
using std::pair;
using std::map;

namespace introduction {
  void g() {
    vector<double> v = {1, 2, 3.456, 99.99};
    list<pair<string, string>> languages = {
      {"Nygaard", "Simula"}, {"Richards", "BCPL"}, {"Ritchie", "C"}
    };

    static map<vector<string>, vector<int>> years = {
      {{"Maurice", "Vincent", "Wilkes"}, {1913, 1945, 1951, 1967, 2000}},
      {{"Martin", "Richards"}, {1982, 2003, 2007}},
      {{"David", "John", "Wheeler"}, {1927, 1947, 1951, 2004}}
    };
    years.insert({{"Bjarne", "Stroustrup"}, {1950, 1975, 1985}});
  }

  void f(std::initializer_list<int> lst) {}

  void h() {
    f({1, 2});
    f({23, 345, 4567, 56789});
    f({});        // the empty list
    //f{1, 2};      // error: function call () missing
  }
}

namespace disambiguation {
  struct X {
    X(initializer_list<int> lst) { cout << "call initializer_list constructor.\n"; }
    X() { cout << "default constructor.\n"; }
    X(int i) { cout << "ordinary constructor.\n"; }
  };

  void f() {
    X x0{};     // call default constructor
    X x1{1};    // call initializer_list constructor
    X x2(2);    // call ordinary constructor
  }
}

namespace use {
  void f(initializer_list<int> args) {
    for(int i = 0; i != args.size(); ++i)
      cout << args.begin()[i] << '\n';
    for(auto p = args.begin(); p != args.end(); ++p)
      cout << *p << '\n';
    for(auto x : args)
      cout << x << '\n';
  }
}

namespace direct_copy {
  vector<vector<double>> vs = {
    {10, 11, 12, 13},                 // OK: vector of four elements
    {10},                             // OK: vector of one element
    // 10,                            // error: vector<double>(int) is explicit
    vector<double>{10, 11, 12},       // OK
    vector<double>{10},               // OK: vector of one element with value 10.0
    vector<double>(10)                // OK: vector of 10 elements with value 0.0
  };

  vector<double> v1(7);               // OK: v1 has 7 elements
  // vector<double> v2 = 9;           // error: no conversion from int to vector
  
  void f(const vector<double>&);
  void g() {
    //v1 = 9;       // error: no conversion from int to vector
    //f(9);         // error: no conversion from int to vector
  }

  vector<double> v11{7};
  vector<double> v22 = {9};
  void h() {
    v11 = {9};    // OK: v11 now has one element (with the value 9)
    f({9});       // OK: f is called with the list {9}
  }
}

vector<double> v1;
void f(const vector<double>&);
void g() {
  v1 = {9, 10, 11}; // OK
  f({9, 8, 7});
}

int main() {
  introduction::g();
  introduction::h();
  disambiguation::f();

  use::f({1, 2, 3, 4, 5});
}
