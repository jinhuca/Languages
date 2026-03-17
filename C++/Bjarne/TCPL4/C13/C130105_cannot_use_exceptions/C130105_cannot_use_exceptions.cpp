// C130105_cannot_use_exceptions.cpp
#include <iostream>
#include <utility>
#include <vector>

using std::pair;
using std::vector;

struct X {
  X(int a, int b) :x{a}, y{b} {
    if(a + b > 100) {
      error_code = 1;
      x = 0;
      y = 0;
    }
  }
  int invalid() const {
    return error_code;
  }
private:
  int x, y;
  int error_code;
};

void minic_raii(int n, int m) {
  X x(n, m);
  if(x.invalid()) {
    // ... deal with error ...
  }
  // ...
}

pair<vector<int>, int> make_vector(int n) {
  if(n > 0 && n < 10)
    return pair<vector<int>, int>{vector<int>(n), 0};
  return pair<vector<int>, int>{vector<int>(0), 1};
}

void return_value_or_exception(int n) {
  auto v = make_vector(n);    // return a pair
  if(v.second) {
    // ... deal with error ...
  }
  auto val = v.first;
  // ...
}

int main() {
  minic_raii(41, 120);
}
