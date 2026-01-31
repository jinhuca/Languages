#pragma once
template<typename C>
class String {
public:
  String();
  C& operator[](int n);             // unchecked element access
  String& operator+=(C c);          // add c at end
private:
  static const int short_max = 15;  // for the short-string optimization ($19.3.3)
  int sz;                           // number of Cs
  char* ptr;
  union {
    int space;                      // unused allocated space for long strings
    C ch[short_max + 1];            // storage for short strings
  };
};