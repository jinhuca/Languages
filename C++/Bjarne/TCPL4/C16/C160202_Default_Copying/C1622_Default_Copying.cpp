// C1622_Default_Copying.cpp 
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

void Date::add_year(int n) { y += n; }
void Date::add_month(int n) { m += n; }
void Date::add_day(int n) { d += n; }

Date my_birthday(1, 23, 1970);

void f(Date& d) {
  d = my_birthday;
}

int main() {
  Date d1 = my_birthday;      // initialization by copy
  Date d2 { my_birthday };    // initialization by copy
  Date d3;
  f(d3);
}
