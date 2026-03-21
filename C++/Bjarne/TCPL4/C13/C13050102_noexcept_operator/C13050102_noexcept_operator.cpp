// C13050102_noexcept_operator.cpp 
#define _SILENCE_CXX20_IS_POD_DEPRECATION_WARNING
#include <iostream>
#include <exception>
#include <vector>

struct A { int m; };                  // POD type
class B : public A { int m; };        // Not POD (different access control/inheritance)
struct C { virtual void foo() {} };     // Not POD (virtual function)

template<typename T>
void my_fct(T& x) noexcept(std::is_pod<T>()) {
  throw std::runtime_error("ah");
}

template<typename T>
void call_f(std::vector<T>& v) noexcept(noexcept(f(v[0]))) {
  for(auto x : v)
    f(x);
}

template<typename T, size_t N>
void swap(T(&a)[N], T(&b)[N]) noexcept(noexcept(swap(*a, *b))) {
}

int main() {
  A a;
  B b;
  C c;
  my_fct(a);
  my_fct(b);
  my_fct(c);
}
