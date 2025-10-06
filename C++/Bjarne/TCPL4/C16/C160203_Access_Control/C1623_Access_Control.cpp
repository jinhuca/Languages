// C1623_Access_Control.cpp 
import std;

class Date {
  int d, m, y;
public:
  void init(int dd, int mm, int yy);      // initialize
  void add_year(int n);                   // add n years
  void add_month(int n);                  // add n months
  void add_day(int n);                    // add n days
};

void timewarp(Date& d) {
  //d.y -= 200;                             // error: Date::y is private
  d.add_year(-200);                     // update object
}

void Date::init(int dd, int mm, int yy) {
  d = dd;
  m = mm;
  y = yy;
}

void Date::add_day(int n) {
  d += n;
}

void Date::add_month(int n) {
  m += n;
}

void Date::add_year(int n) {
  y += n;
}

int main() {
  Date d1;
  d1.init(3, 11, 1990);
  timewarp(d1);
}
