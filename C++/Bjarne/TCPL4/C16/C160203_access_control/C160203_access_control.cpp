// C160203_access_control.cpp 
#include <iostream>

class Date {
  int d, m, y;
public:
  void init(int dd, int mm, int yy);      // initialize
  void add_year(int n);                   // add n years
  void add_month(int n);                  // add n months
  void add_day(int n);                    // add n days
};

void Date::init(int dd, int mm, int yy) {
  d = dd;
  m = mm;
  y = yy;
}

void timewarp(Date& d) {
  // d.y -= 200;              // error: Date::y is private
}

void f() {
  Date d;
  // d.d = 1;                 // error: Date::d is private
  d.init(1, 10, 2020);        // OK: Date::init() is public
}

int main() {
}
