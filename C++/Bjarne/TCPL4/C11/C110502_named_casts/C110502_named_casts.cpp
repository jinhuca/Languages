// C110502_named_casts.cpp 
#include <iostream>

void* my_allocator(size_t s) {
  return std::malloc(s);
}

void f() {
  int* p = static_cast<int*>(my_allocator(100));  // new allocation used as ints
}

void cast() {
  char x = 'a';
  // int* p1 = &x;                            // error: no implicit char* to int* conversion
  // int* p2 = static_cast<int*>(&x);         // error: no implicit char* to int* conversion
  int* p3 = reinterpret_cast<int*>(&x);       // OK: on your head be it
  char* c3 = reinterpret_cast<char*>(&p3);    // OK

  struct B {/*...*/ };
  struct D :B {/*...*/ };

  B* pb = new D;                    // OK: implicit conversion from D* to B*
  //D* pd = pb;                     // error: no implicit conversion from B* to D*
  D* pd = static_cast<D*>(pb);      // OK
}

int main() {
  f();
  cast();
}
