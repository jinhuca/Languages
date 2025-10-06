// C0721_voidPtr.cpp
import std;

void f(int* pi) {
  void* pv = pi;      // ok: implicit conversion of int* to void*
  //auto x = *pv;     // error: can't dereference void*
  //++pv;             // error: can't increment void* (the size of the object pointed to is unknown)

  int* pv2 = static_cast<int*>(pv);   // explicit conversion back to int*

  //double* pd1 = pv;   // error
  //double* pd2 = pi;   // error
  double* pd3 = static_cast<double*>(pv);   // unsafe

  int x = 123;
  int* pi = &x;
  double* pd = static_cast<double*>(pi);

  void* pv1 = pi;
  double* pd1 = static_cast<double*>(pv1);
}

int main() {
  int x = 12;
  f(&x);
}
