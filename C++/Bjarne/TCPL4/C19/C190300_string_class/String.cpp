#include "String.h"

// default constructor: x{""}
String::String() : sz{0}, ptr{ch} {   // ptr points to elements, ch is an initial location
  ch[0] = 0;
}

// ordinary constructor
String::String(const char* p)
  : sz{strlen(p)}
  , ptr{(sz <= short_max) ? ch : new char[sz + 1]}
  , space{0} {
  strcpy(ptr, p);     // copy characters into ptr from p
}

// copy constructor
String::String(const String&) {
}

