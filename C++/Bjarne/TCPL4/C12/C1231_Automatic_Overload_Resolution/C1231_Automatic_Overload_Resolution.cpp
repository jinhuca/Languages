// C1231_Automatic_Overload_Resolution.cpp 
import std;

namespace F1 {
  void print(double d) {
    std::cout << "print double - " << d << '\n';
  }

  void print(long l) {
    std::cout << "print long - " << l << '\n';
  }

  void f() {
    print(1L);
    print(1.0);
    //print(1);       // error: ambiguous: print(long(1)) or print(double(1))?
  }
}

namespace F2 {
  void print(int i) {
    std::cout << "print long - " << i << '\n';
  }
  void print(const char* c) {
    std::cout << "print C-style string - " << c << '\n';
  }
  void print(double d) {
    std::cout << "print double - " << d << '\n';
  }
  void print(long l) {
    std::cout << "print long - " << l << '\n';
  }
  void print(char c) {
    std::cout << "print char - " << c << '\n';
  }

  void f(char c, int i, short s, float f) {
    print(c);           // exact match: invoke print(char)
    print(i);           // exact match: invoke print(int)
    print(s);           // integral promotion: invoke print(int)
    print(f);           // float to double promotion: print(double)

    print('a');       // exact match: invoke print(char)
    print(49);        // exact match: invoke print(int)
    print(0);         // exact match: invoke print(int)
    print("a");       // exact match: invoke print(const char*)
    print(nullptr);   // nullptr_t to const char* promotion: invoke print(const char*)
  }
}

int main() {
  F1::f();
}
