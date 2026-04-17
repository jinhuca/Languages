// C230202_template_instantiation.cpp 
#include <iostream>

template<typename C>
class String {
public:
  String();
  C& operator[](int n) { return ptr[n]; }   // unchecked element access
  String& operator+=(C c);                  // add c at end
  String& operator=(C* c);                   // assign c to

private:
  static const int short_max = 15;          // for the short-string optimization
  int sz;                                   // number of Cs
  char* ptr;
  union {
    int space;                              // unused allocated space size
    C ch[short_max + 1];                    // leave space for terminating 0
  };
};

template<typename C>
String<C>::String()               // String<C>'s constructor
  : sz{0}, ptr{ch} {              // short string: point to ch
  ch[0] = {};                     // terminating 0 of the appropriate character type
}

template<typename C>
String<C>& String<C>::operator+=(C c) {
  // ... add c to the end of this string ...
  return *this;
}

template<typename C>
String<C>& String<C>::operator=(C* c) {
  // ... assign c to 
  return *this;
}

void f() {
  String<char> cs;          // template instantiation
  cs += 'h';
}

int main() {
}
