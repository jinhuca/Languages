// C1101.cpp : Output
import std;

void f() {
  int x { 10 };
  std::cout << x << '\n';
}
void h(int i) {
  std::cout << "the value of i is ";
  std::cout << i;
  std::cout << '\n';
}

void h2(int i) {
  std::cout << "the value of i is " << i << '\n';
}

void g() {
  int b = 'b';
  char c = 'c';
  std::cout << 'a' << b << c;
}

int main() {
  f();
  h(11);
  h2(12);
  g();
}
