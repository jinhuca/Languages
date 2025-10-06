// C17050103_Meaning_of_Copy.cpp 
import std;

struct S {
  int* p;
};

S x { new int{0} };

void f() {
  S y { x };              // "copy" x
  *y.p = 1;               // change y; affects x
  *x.p = 2;               // change x; affects y
  delete y.p;             // affects x and y
  y.p = new int { 3 };    // OK: change y; does not affect x
  *x.p = 4;               // oops: write to deallocated memory
}

int main() {
  f();
}