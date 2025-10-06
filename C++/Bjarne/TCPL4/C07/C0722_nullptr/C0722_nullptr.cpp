// C0722_nullptr.cpp :
// nullptr - pointer to nothing
import std;

void f() {
  int* pi = nullptr;      // nullptr can be assigned to any pointer.
  double* pd = nullptr;
  //std::cout << *pd << '\n';   // it's run-time error to deference nullptr
  //int i = nullptr;        // error: i is not a pointer

  int* x = 0;       // x gets the value nullptr
}

int main() {
  f();
}
