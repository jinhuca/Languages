// C16020501_Constructors_Default_Arguments.cpp
import std;

class Date {
  int d, m, y;
public:
  Date(int dd = 0, int mm = 0, int yy = 0);
  // ...
};

Date today { 12,9,2010 };

Date::Date(int dd, int mm, int yy) {
  d = dd ? dd : today.d;
  m = mm ? mm : today.m;
  y = yy ? yy : today.y;
}

void f() {
  Date d1 { 2,12,2010 };
  Date d2 { 0, 1, 1910 };
}

int main() {
  f();
}
