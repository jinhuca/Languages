// C230200_simple_string_template.cpp bb 
#include <iostream>
#include <map>
#include <algorithm>

template<typename C>
class String {
public:
  String() {}
  C& operator[](int n) { return ptr[n]; }   // unchecked element access
  String& operator+=(C c);                  // add c at end

private:
  static const int short_max = 15;          // for the short-string optimization
  int sz;                                   // number of Cs
  char* ptr;
  union {
    int space;                              // unused allocated space size
    C ch[short_max + 1];                    // leave space for terminating 0
  };
};

void f() {
  String<char> cs;
  String<unsigned char> us;
  String<wchar_t> ws;

  struct Jchar {};
  String<Jchar> js;
}

void g() {
  std::map<String<char>, int> m;
  for(String<char> buf; std::cin >> buf;) {
    ++m[buf];
  }
}

void h() {
  std::map<std::string, int> m;
  for(std::string buf; std::cin >> buf;) {
    ++m[buf];
  }
}

int main() {
}
