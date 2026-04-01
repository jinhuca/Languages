// C160212_static_members.cpp 
#include <iostream>

class Date {
  int d, m, y;
  static Date default_date;   // static data member declaration
public:
  Date(int dd = 0, int mm = 0, int yy = 0);
  // ...
  static void set_default(int, int, int);  // static member function
};

Date Date::default_date{16, 12, 1770};    // 

void Date::set_default(int d, int m, int y) {
  default_date = {d, m, y};               // assign to the static data member
}

Date::Date(int dd, int mm, int yy) {
  d = dd ? dd : default_date.d;
  m = mm ? mm : default_date.m;
  y = yy ? yy : default_date.y;
  // ... check that the Date is valid
}

void f() {
  Date::set_default(4, 5, 1945);  // call Date's static member function
}

int main() {
  std::cout << "Hello World!\n";
}
