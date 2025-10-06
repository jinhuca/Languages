// C076_Pointer_Ownership.cpp
import std;

void confuse(int* p) {
  std::cout << *p << '\n';
  delete p;
}

int global { 7 };

void f() {
  int* pn = new int { 7 };
  int i { 7 };
  int* q = &i;
  confuse(pn);
  confuse(q);
  confuse(&global);
}

int main() {
  f();
}
