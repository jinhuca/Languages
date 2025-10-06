export module String;

import std;

export class String {
public:
  String();                           // default constructor: String x{""}
  String(const char* p);              // constructor from C-style string: String x{"Euler"}
  String(const String&);              // copy constructor
  String& operator=(const String&);   // copy assignment
  String(String&&);                   // move constructor
  String& operator=(String&&);        // move assignment
  ~String() {}

  // -- Access to characters
  char& operator[](int n) { return ptr[n]; }    // unchecked element access
  char operator[](int n) const { return ptr[n]; }

  char& at(int n) { check(n); return ptr[n]; }  // range-checked element access
  char at(int n) const { check(n); return ptr[n]; }

  String& operator+=(char c);                   // add c at end

  char* c_str() { return ptr; }                 // C-style string access
  const char* c_str() const { return ptr; }

  int size() const { return sz; }               // number of elements
  int capacity() const {                        // elements plus available space
    return (sz <= short_max) ? short_max : sz + space;
  }
private:
  static const int short_max = 15;
  int sz;
  char* ptr;
  union {
    int space;                      // unused allocated space
    char ch[short_max + 1];         // leave space for terminating 0
  };
  void check(int n) const {         // range check
    if(n < 0 || sz <= n)
      throw std::out_of_range("String::at()");
  }
  // ancillary member functions
  void copy_from(const String&);
  void move_from(String&);
};