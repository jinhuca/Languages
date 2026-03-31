// C16020901_constant_member_functions.cpp 
#include <iostream>

class Date {
  int d, m, y;
public:
  int day() const;
  int month() const { return m; }
  int year() const { return y; }

  void add_year(int n) { y += n; }
};

int Date::day() const {
  return d;
}

void f(Date& d, const Date& cd) {
  int i = d.year();   // ok: year() is a const member function
  d.add_year(1);      // ok: add_year() is a non-const member function
  int j = cd.year();  // ok: year() is a const member function
  //cd.add_year(1);     // error: add_year() is a non-const member function
}

int main() {
  Date today;
  Date tomorrow;
  f(today, tomorrow);
}
