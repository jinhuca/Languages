// C06362_Auto.cpp
import std;

void f() {
  char v1 = 12345;      // 12345 is an int (not an int&)
  int v2 = 'c';         // 'c' is a char
  auto x1 { 1 };
  auto x2 = { 1, 2, 3 };
}

int main() {
  f();
}
