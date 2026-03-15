// C120108_local_variables.cpp 
#include <iostream>

void f(int a) {
  while(a--) {
    static int n = 0;     // static local variable, initialized only once.
    int x = 0;            // non-static local variable, initialized 'a' times in each call of f()
    std::cout << "n == " << n++ << ", x == " << x++ << '\n';
  }
}

int fn(int n) {
  static int n1 = n;                // OK
  static int n2 = fn(n - 1) + 1;    // recursive initialization -> undefined
  return n;
}

int main() {
  f(3);
  fn(3);
}
