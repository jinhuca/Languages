#include "String.h"

// default constructor: x{""}
// ptr points to elements, ch is an initial location
String::String() : sz{0}, ptr{ch} {
  ch[0] = 0;        // terminating 0
}

// ordinary constructor: C-style string as argument
String::String(const char* p)
  : sz{static_cast<int>(strlen(p))},
  ptr{(sz <= short_max) ? ch : new char[sz + 1]},
  space{0} {
  strcpy(ptr, p);
}

// copy constructor
String::String(const String& x) {
  copy_from(x);     // copy representation from x
}

// move constructor
String::String(String&& x) noexcept {
  move_from(x);
}

// copy assignment
String& String::operator=(const String& x) {
  if(this == &x) return *this;      // deal with self-assignment
  char* p = (short_max < sz) ? ptr : 0;
  copy_from(x);
  delete[] p;
  return *this;
}

// move assignment
String& String::operator=(String&& x) noexcept {
  if(this == &x) return *this;      // deal with self-assignment (x = move(x) is insanity)
  if(short_max < sz) delete[] ptr;  // delete target
  move_from(x);                     // does not throw
  return *this;
}

// ancillary functions
char* expand(const char* ptr, int n) {                // expand into free store
  // n should be at least std::strlen(ptr) + 1
  char* p = new char[n];
  // use secure overload: destination buffer size is 'n'
  strcpy_s(p, static_cast<size_t>(n), ptr);
  return p;
}

// adds a character to the end of the string, and increases its size by one
String& String::operator+=(char c) {
  if(sz == short_max) {     // expand to long string
    int n = sz + sz + 2;    // double the allocation (+2 because of the terminating 0)
    ptr = expand(ptr, n);
    space = n - sz - 2;
  }
  else if(short_max < sz) {
    if(space == 0) {        // expand in free store
      int n = sz + sz + 2;
      char* p = expand(ptr, n);
      delete[] ptr;
      ptr = p;
      space = n - sz - 2;
    }
    else {
      --space;
    }
  }
  ptr[sz] = c;      // add c at end
  ptr[++sz] = 0;    // increase size and set terminator
  
  return *this;
}

std::ostream& operator<<(std::ostream& os, const String& s) {
  return os << s.c_str();
}

std::istream& operator>>(std::istream& is, String& s) {
  s = "";         // clear the target string
  is >> std::ws;  // skip whitespace
  char ch = ' ';
  while(is.get(ch) && !isspace(ch))
    s += ch;
  return is;
}

bool operator==(const String& a, const String& b) {
  if(a.size() != b.size())
    return false;
  for(int i = 0; i != a.size(); ++i)
    if(a[i] != b[i])
      return false;
  return true;
}

bool operator!=(const String& a, const String& b) {
  return !(a==b);
}

bool operator<(const String& a, const String& b) {
  return false;
}

bool operator>(const String& a, const String& b) {
  return false;
}

bool operator<=(const String& a, const String& b) {
  return false;
}

bool operator>=(const String& a, const String& b) {
  return false;
}

char* begin(String& x) {
  return x.c_str();
}

char* end(String& x) {
  return x.c_str() + x.size();
}

const char* begin(const String& x) {
  return x.c_str();
}

const char* end(const String& x) {
  return x.c_str() + x.size();
}

String& operator+=(String& a, const String& b) {
  for(auto x : b)
    a += x;
  return a;
}

String operator+(const String& a, const String& b) {
  String res{a};
  res += b;
  return res;
}

String operator""_s(const char* p, size_t) { return String{p}; }

void String::copy_from(const String& x) {   // make *this a copy of x
  if(x.sz <= short_max) {                   // copy *this
    memcpy(this, &x, sizeof(x));            // C43.5
    ptr = ch;
  }
  else {                                    // copy the elements
    ptr = expand(x.ptr, x.sz + 1);
    sz = x.sz;
    space = 0;
  }
}

void String::move_from(String& x) {
  if(x.sz <= short_max) {                   // copy *this
    memcpy(this, &x, sizeof(x));            // C43.5
    ptr = ch;
  }
  else {                                    // grab the elements
    ptr = x.ptr;
    sz = x.sz;
    space = x.space;
    x.ptr = x.ch;                           // x = ""
    x.sz = 0;
    x.ch[0] = 0;
  }
}
