// C120301_automatic_overload_resolution.cpp 
#include <iostream>
using std::cout;

void print(int i) { cout << "print integer: " << i << '\n'; }
void print(char c) { cout << "print char: " << c << '\n'; }
void print(const char* s) { cout << "print const char*: " << s << '\n'; }
void print(double d) { cout << "print double: " << d << '\n'; }
void print(long l) { cout << "print long: " << l << '\n'; }

void f() {
  print(1L);            // print(long)
  print(1.0);           // print(double)
  // print(1);          // error, ambiguous: 1 can be equally converted to long or double
}

void h(char c, int i, short s, float f) {
  print(c);             // exact match: invoke print(char)
  print(i);             // exact match: invoke print(int)
  print(s);             // integral promotion: invoke print(int)
  print(f);             // float to double promotion: print(double)

  print('a');           // exact match: invoke print(char)
  print(49);            // exact match: invoke print(int)
  print(0);             // exact match: invoke print(int)
  print("a");           // exact match: invoke print(const char*)
  //print(nullptr);       // nullptr_t to const char* promotion: invoke print(const char*)
}

// without overloading functions
void print_int(int i) { cout << "print_int(" << i << ").\n"; }
void print_char(char c) { cout << "print_char(" << c << ").\n"; }
void print_string(const char* s) { cout << "print_string(" << s << ").\n"; }

void g(int i, char c, const char* p, double d) {
  print_int(i);         // OK
  print_char(c);        // OK
  print_string(p);      // OK

  print_int(c);         // OK? calls print_int(int(c)), prints a number
  print_char(i);        // OK? calls print_char(char(i)), narrowing
  // print_string(i);   // error: no conversion from integer to const char*
  print_int(d);         // OK? calls print_int(int(d)), narrowing
}

int main() {
  f();
  h('c', 10, 23, 1.23f);
  g(23, 'x', "overload", 1.21);
}
