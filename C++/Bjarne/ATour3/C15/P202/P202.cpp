// P202.cpp - std::array
import std;

void f() {
  std::array<int, 3> a1 { 1,2,3 };
}

void f1(int* p, int sz) {       // C-Style interface

}

void useF1()
{
  std::array<int, 10> a { 1,2,3 };
  f1(a.data(), a.size());   // pass std::array in C-Style use
}

int main() {
  std::array<int, 3> a1 = { 1,2,3 };
  auto a2 = a1;       // copy
  a2[1] = 5;
  a1 = a2;                        // assign
}
