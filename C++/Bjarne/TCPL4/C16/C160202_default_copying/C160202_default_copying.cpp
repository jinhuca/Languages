// C160202_default_copying.cpp 
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

void f() {
  Date my_birthday;                     // a global variable of type Date
  Date d1 = my_birthday;                // copy my_birthday to d1
  Date d2{my_birthday};                 // copy my_birthday to d2
}

int main() {
  std::cout << "Hello World!\n";
}
