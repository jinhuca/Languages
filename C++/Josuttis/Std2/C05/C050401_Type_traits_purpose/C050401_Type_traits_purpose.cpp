// C050401_Type_traits_purpose.cpp 
import std;

template<typename T>
void foo(const T& val) {
  if (std::is_pointer<T>::value) {
    std::cout << "foo() called for a pointer.\n";
  }
  else {
    std::cout << "foo() called for a value.\n";
  }
}

void f1() {
  int x = 42;
  foo(x);       // T is int
  foo(&x);      // T is int*
}

int main() {
  f1();
}
