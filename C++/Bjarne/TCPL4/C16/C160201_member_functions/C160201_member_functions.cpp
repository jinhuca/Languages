// C160201_member_functions.cpp 
#include <iostream>

struct Date {     // representation
  int d, m, y;

  void init(int dd, int mm, int yy);  // initialize
  void add_year(int n);               // add n years
  void add_month(int n);              // add n months
  void add_day(int n);                // add n days
};

void Date::init(int dd, int mm, int yy) {
  d = dd;
  m = mm;
  y = yy;
}

Date my_birthday;                     // a global variable of type Date

void f() {
  Date today;                         // a local variable of type Date
  today.init(16, 10, 1986);           // initialize today to January 1, 2024
  my_birthday.init(30, 12, 1950);     // initialize my_birthday to December 30, 1950

  Date tomorrow = today;              // copy today to tomorrow
  tomorrow.add_day(1);                // add one day to tomorrow
}

int main() {
  std::cout << "Hello World!\n";
}
