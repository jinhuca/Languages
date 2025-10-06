// P105.cpp
import std;

class ExceptionClass {};

// the arguments are positive and a < b < c
int my_complicated_function(int a, int b, int c) {
  if (!(0 < a && a < b && b < c)) {
    throw new ExceptionClass();
  }
  // ...
  return 1;
}

bool ordered_positive(int a, int b, int c) {
  return 0 < a && a < b && b < c;
}

int function1(int a, int b, int c) {
  return 0;
}

int main() {
  std::cout << "Hello World!\n";
}
