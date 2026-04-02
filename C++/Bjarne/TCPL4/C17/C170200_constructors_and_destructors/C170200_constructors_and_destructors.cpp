// C170200_constructors_and_destructors.cpp 
#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::clog;
using std::vector;

struct Tracer {
  string mess;
  Tracer(const string& s) : mess{s} { clog << mess; }
  ~Tracer() { clog << '~' << mess; }
};

void f(const vector<int>& v) {
  Tracer tr{"in f()\n"};
  for(auto x : v) {
    Tracer tr{string{"v loop "} + std::to_string(x) + '\n'};
    // ... do something with x
  }
}

int main() {
  f({2,3,5,7});
}
