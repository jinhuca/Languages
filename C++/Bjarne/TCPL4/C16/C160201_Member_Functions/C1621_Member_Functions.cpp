// C1621_Member_Functions.cpp 
import std;

struct Date {
  int d, m, y;

  void init(int dd, int mm, int yy);    // initialize
  void add_year(int n);                 // add n years
  void add_month(int n);                // add n months
  void add_day(int n);                  // add n days
};

void Date::init(int dd, int mm, int yy) {
  d = dd;
  m = mm;
  y = yy;
}

void Date::add_year(int n) {
  y += n;
}

void Date::add_month(int n) {
  m += n;
}

void Date::add_day(int n) {
  d += n;
}

Date my_birthday;

void f() {
  Date today;
  today.init(16, 10, 1996);
  my_birthday.init(30, 12, 1950);

  Date tomorrow = today;
  tomorrow.add_day(1);
  // ...
}

int main() {
  f();
}
