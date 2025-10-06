// C1111_Logical_Ops.cpp
import std;

void f(char* p) {
  if (p && *p == 'a') {
    std::cout << *p << '\n';
  }
}

int main() {
  const char* p1 = "asffwe";
  const char* p2 = nullptr;
  const char* p3 = "fsew";

  f(const_cast<char*>(p1));
  f(const_cast<char*>(p2));
  f(const_cast<char*>(p3));
}
