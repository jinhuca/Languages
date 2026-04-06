#pragma once
#include <exception>
#include <stdexcept>

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

  String(String&&);                                     // move constructor
  String& operator=(String&&);                          // move assignment

  ~String() { if(short_max < sz) delete[] ptr; }        // destructor

  // access to characters
  char& operator[](int n) { return ptr[n]; }            // unchecked element access
  char operator[](int n) const { return ptr[n]; }

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

