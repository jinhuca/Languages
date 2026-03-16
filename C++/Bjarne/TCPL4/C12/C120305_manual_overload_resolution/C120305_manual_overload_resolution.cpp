// C120305_manual_overload_resolution.cpp 
#include <iostream>

void f1(char c) { std::cout << "call f1(char).\n"; }
void f1(long l) { std::cout << "call f1(long).\n"; }
void f1(int n) { f1(long(n)); }

void f2(char* pc) { std::cout << "call f2(char*).\n"; }
void f2(int* pi) { std::cout << "call f2(int*).\n"; }

void k(int i) {
  f1(i);          // ambiguous: f1(char) or f1(long)? - add f1(int n) to overload
  //f2(0);        // ambiguous: f2(char*) or f2(int*)? - casting to call
  f2(static_cast<int*>(nullptr));
}

int main() {
  std::cout << "Hello World!\n";
}
