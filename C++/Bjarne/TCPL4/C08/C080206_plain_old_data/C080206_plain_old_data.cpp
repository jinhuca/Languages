// C080206_plain_old_data.cpp 
#include <iostream>
#include <type_traits>

// a POD
struct S0 {};

// a POD
struct S1 { int a; };

// not a POD - no default constructor
struct S2 { int a; S2(int aa) :a(aa) {} };

// a POD - defaulted default constructor
struct S3 { int a; S3(int aa) : a(aa) {} S3() {}; };

// a POD - defaulted default constructor
struct S4 { int a; S4(int aa) : a(aa) {} S4() = default; };

// not a POD (has a virtual function)
struct S5 { int a; virtual void f() {} };

// a POD
struct S6 : S1 {};

// a POD
struct S7 : S0 { int b; };

// not a POD (data in both S1 and S8)
struct S8 : S1 { int b; };

// a POD
struct S9 : S1 {};

template<typename T>
void mycopy(T* dest, const T* src, size_t n) {
  if(std::is_pod<T>::value) {
    std::memcpy(dest, src, n * sizeof(T));
  }
  else {
    for(size_t i = 0; i != n; ++i) {
      dest[i] = src[i];
    }
  }
}

int main() {
  std::cout << "Hello World!\n";
}
