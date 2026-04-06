#include <iostream>
#include "Ptr.h"

struct record { int a, b; };

void f1(record a) {    // traditional use - unchecked for pointer range
  record v[200]{};
  record* p = &v[0];
  p--;
  *p = a;       // oops: p out of range, and not throw exception
  ++p;
  *p = a;       // OK
}

template<typename U>
void f2(Ptr<U> a) {     // checked - class Ptr
  U v[200]{};
  Ptr<record> p(&v[0], v);
  p--;
  *p = *a;
  ++p;
  *p = *a;
}

template<typename T>
void f3(T a) {              // checked
  T v[200]{};
  Ptr<T> p(&v[0], v);
  p.operator--(0);          // postfix: p--
  p.operator*() = a;        // run-time error: p out of range
  p.operator++();           // prefix: ++p
  p.operator*() = a;        // OK
}

int main() {
  record r1{1, 2};
  f1(r1);

  int arr[3]{10, 20, 30};
  Ptr<int> p(&arr[0], arr, 3);
  ++p;
  int v = *p;

  std::cout << v << '\n';
}