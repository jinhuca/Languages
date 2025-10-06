// C1221_Reference_Arguments.cpp 
import std;

void f(int val, int& ref) {
  ++val;
  ++ref;
}

void g() {
  int i = 1;
  int j = 1;
  f(i, j);
  std::cout << "i by value:\t" << i << '\n';
  std::cout << "j by ref:\t" << j << '\n';
}

int main() {
  g();
}
