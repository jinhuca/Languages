// C110201_memory_management.cpp 
#include <iostream>
#include <string>
#include <memory>

void very_bad_code_premature_deletion() {
  int* p1 = new int {99};
  int* p2 = p1;               // potential trouble
  delete p1;                  // now p2 doesn't point to a valid object
  p1 = nullptr;               // gives a false sense of safety
  char* p3 = new char {'x'};   // p3 may now point to the memory pointed to by p2
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

std::string reverse(const std::string& s) {
  std::string ss;
  for(int i = s.size() - 1; 0 <= i; --i)
    ss.push_back(s[i]);
  return ss;                  // move, rather than copy ss.
}

void f(int n) {
  int* p1 = new int[n];
  std::unique_ptr<int[]> p2 {new int[n]};
  // ...
  if(n%2) throw std::runtime_error("odd");
  delete[] p1;                // program may never get here.
}

int main() {
  very_bad_code_premature_deletion();
  sloppy_code_with_multiple_deletion();
}
