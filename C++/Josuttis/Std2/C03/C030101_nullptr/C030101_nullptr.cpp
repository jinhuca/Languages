// C030101_nullptr.cpp: nullptr and std::nullptr
import std;

void f(int x) {
  std::cout << "calls void f(int)\n";
}

void f(void* p) {
  std::cout << "calls void f(void*)\n";
}

void g() {
  f(0);            // calls void f(int)
  f(nullptr);      // calls void f(void*)
  f(1);            // calls void f(int)
}

int main() {
  g();
}
