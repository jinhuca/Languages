// C1121_Memory_Management.cpp 
import std;

void trouble() {
  int* p1 = new int { 99 };
  int* p2 = p1;                     // potential trouble
  delete p1;                        // now p2 doesn't point to a valid object
  p1 = nullptr;                     // gives a false sense of safety
  char* p3 = new char { 'x' };      // p3 may now point to the memory pointed by p2
  *p2 = 999;                        // this may cause trouble
  std::cout << *p3 << '\n';         // may not print x
}

void sloppy() {                     // very bad code
  int* p = new int[1000];           // acquire memory
  // ... use *p ...
  delete[] p;                       // release memory

  // ... wait a while ...

  delete[] p;                       // but sloppy() does not own *p
}

int main() {
  trouble();
}
