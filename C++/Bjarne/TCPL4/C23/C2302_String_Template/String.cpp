#include "String.h"

template<typename C>
String<C>::String<C>() : sz(0), ptr(nullptr) {
  ch[0] = C();
}

template<typename C>
C& String<C>::operator[](int n) {
  return (ptr ? ptr : ch)[n];
}

template<typename C>
String<C>& String<C>::operator+=(C c) {
  if (sz < short_max) {
    ch[sz++] = c;
    ch[sz] = C();
  }
  else {
    if (!ptr) {
      // switch to long-string representation
      int new_space = short_max * 2;
      ptr = new C[sz + new_space + 1];
      for (int i = 0; i < sz; ++i) ptr[i] = ch[i];
      ptr[sz] = C();
      space = new_space;
    }
    else if (space == 0) {
      // need more space
      int new_space = sz; // double the space
      C* p = new C[sz + new_space + 1];
      for (int i = 0; i < sz; ++i) p[i] = ptr[i];
      delete[] ptr;
      ptr = p;
      space = new_space;
    }
    ptr[sz++] = c;
    ptr[sz] = C();
    --space;
  }
  return *this;
}