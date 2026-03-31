// C160206_explicit_constructors.cpp 
#include <iostream>
#include <complex>

void use_implicit_constructors() {
  std::complex<double> d{1};    // implicit call to std::complex<double>::complex(double)
  std::cout << d << '\n';
}

class Date {
  int d, m, y;
public:
  Date(int dd = 0, int mm = 0, int yy = 0);
};

Date today{23, 6, 1986};            // global variable initialized by constructor
Date::Date(int dd, int mm, int yy) : d(dd), m(mm), y(yy) {
  d = dd ? dd : today.d;
  m = mm ? mm : today.m;
  y = yy ? yy : today.y;
  // ... check that the date is valid and throw an exception if it is not
}
void my_fct(Date d) {
  std::cout << "my_fct called\n";
}

void use_implicit_Date() {
  Date d{15};     // plausible: d becomes {15, today's month, today's year}
  d = 11;         // obscue
  my_fct(12);     // obscue
}

class Date_explicit {
  int d, m, y;
public:
  explicit Date_explicit(int dd = 0, int mm = 0, int yy = 0);
  // ... other members
};

Date_explicit today_explicit{23, 6, 1986};            // global variable initialized by constructor
Date_explicit::Date_explicit(int dd, int mm, int yy) : d(dd), m(mm), y(yy) {
  d = dd ? dd : today_explicit.d;
  m = mm ? mm : today_explicit.m;
  y = yy ? yy : today_explicit.y;
  // ... check that the date is valid and throw an exception if it is not
}

void my_fct_explicit(Date_explicit d) {
  std::cout << "my_fct_explicit called\n";
}

void use_explicit_constructors() {
  Date_explicit d{15};                    // OK: considered explicit {15, today's month, today's year}
  Date_explicit d2 = Date_explicit{15};   // OK: considered explicit {15, today's month, today's year}
  Date_explicit d3 = {15};                // error: = initialization does not do implicit conversion from int to Date_explicit
  Date_explicit d4 = 15;                  // error: = initialization does not do implicit conversion from int to Date_explicit

  my_fct_explicit(12);                    // error: no implicit conversion from int to Date_explicit
  my_fct_explicit({12});                  // error: no implicit conversion from int to Date_explicit
  my_fct_explicit(Date_explicit{12});     // OK: considered explicit {12, today's month, today's year}
}

struct X {
  explicit X();
  explicit X(int, int);
};

void use_explicit_X() {
  X x1 = {};                // error: implicit
  X x2 = {1, 2};            // error: implicit

  X x3{};                   // OK: explicit
  X x4{1, 2};               // OK: explicit
}

int f(X x) {
  std::cout << "f called\n";
  return 0;
}

int i1 = f({});           // error: no implicit conversion from {} to X
int i2 = f({1, 2});       // error: no implicit conversion from {1, 2} to X

int i3 = f(X{});          // OK: explicit
int x4 = f(X{1, 2});      // OK: explicit

int main() {
  use_implicit_constructors();
  use_implicit_Date();
  use_explicit_constructors();
}
