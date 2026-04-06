// C190206_user_defined_literals.cpp 
#include <iostream>
#include <string>
#include <complex>

using std::complex;
using std::string;

using namespace std::complex_literals;

constexpr std::string operator""_s(const char* p, size_t n) {   // std::string literal
  return std::string(p, n);
}

constexpr unsigned long long operator""_b(unsigned long long v) {
  unsigned long long result = 0;
  unsigned long long base = 1;
  while(v) {
    unsigned digit = v % 10;
    // treat each decimal digit 0/1 as a binary digit (LSB first)
    if(digit) result += base;
    base <<= 1;
    v /= 10;
  }
  return result;
}

void built_in_literals() {
  auto i = 123;           // int
  auto d = 1.2;           // double
  auto f = 1.2F;          // float
  auto c = 'a';           // char
  auto x = 1ULL;          // unsigned long long
  auto y = 0xD0;          // hexademical unsigned
  auto z = "as";          // C-style string (const char[3])
}

void extended_literals() {
  auto s = "Hi!"_s;       // user-defined string literal operator, not "zero-terminated array of char"
  auto i = 1.2i;          // complex imaginary
  constexpr auto b = 10101011110101_b;    // binary
}

int main() {
  built_in_literals();
  extended_literals();
}
