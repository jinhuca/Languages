// C0431_Output.cpp
import std;

void simple_ostream_demo() {
  std::cout << 10;
}

void g() {
  int i { 10 };
  std::cout << i;
}

void h(int i) {
  std::cout << "the value of i is ";
  std::cout << i;
  std::cout << '\n';
}

void h2(int i) {
  std::cout << "the value of i is " << i << '\n';
}

void k() {
  int b = 'b';
  char c = 'c';
  std::cout << 'a' << b << c << '\n';
}

int main() {
  simple_ostream_demo();  std::cout << '\n';
  g();  std::cout << '\n';
  h(11);
  h2(11);
  k();
}
