// C0941_If_statements.cpp 
import std;

void if_bool(bool b) {
  if(b)
    std::cout << "true.\n";
  else
    std::cout << "false.\n";
}

void if_arithmetic(int i) {
  if(i)
    std::cout << i << " is evaluated to true.\n";
  else
    std::cout << i << " is evaluated to false.\n";
}

void if_pointer(int* p) {
  if(p)
    std::cout << "pointer is evaluated to true.\n";
  else
    std::cout << "pointer is evaluated to false.\n";
}

enum E1 { a, b };
enum class E2 { a, b };

void if_enum() {
  E1 e1 = E1::b;
  E2 e2 = E2::b;
  if(e1)
    std::cout << "e1 is true.\n";
  else
    std::cout << "e1 is false.\n";
  //if(e2)      // no conversion from enum class to bool
  //  std::cout << "error.\n";
}

void f(bool b, int i, int* p) {
  if_bool(b);
  if_arithmetic(i);
  if_pointer(p);
  if_enum();
}

void f2(int i) {
  if(i) {
    int x = i + 2;
    ++x;
    // ...
  }
  else {
    //++x;    // error: x is not in scope
  }
  //++x;      // error: x is not in scope
}

void f3(int i) {
  if(i)
    int x = i + 2;    // declaration on if-statement branch
  //++x;    // error: x is not in scope now.
}

int main() {
  bool b = false;
  int i = -2;
  int* p = nullptr;
  f(b, i, p);
}
