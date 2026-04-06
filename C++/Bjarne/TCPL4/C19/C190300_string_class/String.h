#pragma once
#pragma warning(disable : 4996)
#include <exception>
#include <stdexcept>
#include <iostream>

/*
   A simple string that implements the short string optimization
    
    size()==sz is the number of elements
    if size()<=short_max, the characters are held in the String object itself;
    otherwise the free store is used

    ptr points to the start of the character sequence
    the character sequence is kept zero-terminated: ptr[size()]==0;
    this allows us to use C library string functions and to easily return a C-style string: c_str()

    To allow efficient addition of characters at end, String grows by doubling its allocation;
    capacity() is the amount of space available for characters (excluding the terminating 0): sz+space
*/

class String {
public:
  String();                                             // default constructor: x{""}
  String(const char* p);                                // constructor from C-style string: x{"Euler"}
  
  String(const String&);                                // copy constructor
  String& operator=(const String&);                     // copy assignment

  String(String&&) noexcept;                                     // move constructor
  String& operator=(String&&) noexcept;                 // move assignment

  ~String() { if(short_max < sz) delete[] ptr; }        // destructor

  // access to characters
  char& operator[](int n) { return ptr[n]; }            // unchecked element access
  char operator[](int n) const { return ptr[n]; }

  char& at(int n) { check(n); return ptr[n]; }          // range-checked element access
  char at(int n) const { check(n); return ptr[n]; }     //

  String& operator+=(char c);                           // add c at end

  char* c_str() { return ptr; }                         // C-style string access
  const char* c_str() const { return ptr; }

  int size() const { return sz; }                       // number of elements
  int capacity() const {                                // elements plus available space
    return (sz <= short_max) ? short_max : sz + space;
  }

private:
  static const int short_max = 15;
  int sz;                                               // number of characters
  char* ptr;
  union {
    int space;                                          // unused allocated space
    char ch[short_max + 1];                             // leave space for terminating 0
  };

  void check(int n) const {                             // range check
    if(n < 0 || sz <= n)
      throw std::out_of_range("String::at()");
  }

  // ancillary member functions:
  void copy_from(const String& x);
  void move_from(String& x);
};

std::ostream& operator<<(std::ostream& os, const String& s);
std::istream& operator>>(std::istream& is, String& s);

bool operator==(const String& a, const String& b);
bool operator!=(const String& a, const String& b);
bool operator<(const String& a, const String& b);
bool operator>(const String& a, const String& b);
bool operator<=(const String& a, const String& b);
bool operator>=(const String& a, const String& b);

char* begin(String&);   // C-string-style access
char* end(String&);
const char* begin(const String&);
const char* end(const String&);

String& operator+=(String& a, const String& b);   // concatenation
String operator+(const String& a, const String& b);

String operator""_s(const char* p, size_t);       // literals