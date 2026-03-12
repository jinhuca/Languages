// C110201_memory_management.cpp 
#include <iostream>

void very_bad_code_premature_deletion() {
  int* p1 = new int{99};
  int* p2 = p1;               // potential trouble
  delete p1;                  // now p2 doesn't point to a valid object
  p1 = nullptr;               // gives a false sense of safety
  char* p3 = new char{'x'};   // p3 may now point to the memory pointed to by p2
  *p2 = 999;                  // this may cause trouble
  std::cout << *p3 << '\n';   // may not print x
}

void sloppy_code_with_multiple_deletion() {
  int* p = new int[1000];     // acquire memory
  // ... use *p ...
  delete[] p;                 // release memory

  // ... wait a while ...     
  delete[] p;                 // but this function does not own *p anymore
}

int main() {
  very_bad_code_premature_deletion();
  sloppy_code_with_multiple_deletion();
}
