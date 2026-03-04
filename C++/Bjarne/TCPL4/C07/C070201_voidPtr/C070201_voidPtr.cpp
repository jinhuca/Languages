// C0721_voidPtr.cpp
import std;

int function1(double pf) {
  return 1;
}

void function_pointer_example() {
  void* pv;
  //int (*pf0)(double) = pv; // error: cannot convert void* to function pointer type

  void* pv2 = &function1;  // ok: function pointers can be converted to void*
  int (*pf1)(double) = reinterpret_cast<int (*)(double)>(pv2);  // ok: reinterpret_cast can convert between function pointer types, but it's unsafe
  //int (*pf2)(double) = static_cast<int (*)(double)>(pv2);  // error: static_cast cannot convert void* to function pointer type
}

void f(int* pi) {
  void* pv = pi;      // ok: implicit conversion of int* to void*
  //auto x = *pv;     // error: can't dereference void*
  //++pv;             // error: can't increment void* (the size of the object pointed to is unknown)

  int* pv2 = static_cast<int*>(pv);   // explicit conversion back to int*

  //double* pd1 = pv;   // error
  //double* pd2 = pi;   // error
  double* pd3 = static_cast<double*>(pv);   // unsafe

  int x = 123;
  int* pix = &x;
  //double* pd = static_cast<double*>(pv);  // error: can't convert void* to double* even with static_cast
  //double* pd = static_cast<double*>(pi);  // error: can't convert int* to double* even with static_cast
  double* pd = reinterpret_cast<double*>(pi);  // ok: reinterpret_cast allows conversion between unrelated pointer types, but it's unsafe

  void* pv1 = pi;
  double* pd1 = static_cast<double*>(pv1);
}

int main() {
  int x = 12;
  f(&x);
}
