// C160205_constructors.cpp
#include <iostream>

class Date {
  int d, m, y;
public:
  Date(int dd = 0, int mm = 0, int yy = 0);     // constructor: day, month, year with defult values
  Date(int dd, int mm);             // constructor: day, month, today's year
  Date(int dd);                     // constructor: day, today's month and year;
  Date();                           // default constructor: today's day, month and year
  Date(const char* s);              // constructor: convert string to date - date in string representation
};

Date today{23, 6, 1986};            // global variable initialized by constructor

Date::Date(int dd, int mm, int yy) : d(dd), m(mm), y(yy) {
  d = dd ? dd : today.d;
  m = mm ? mm : today.m;
  y = yy ? yy : today.y;
  // ... check that the date is valid and throw an exception if it is not
}

void call_constructor_as_function() {
  Date today = Date(23, 6, 1986);   // call the constructor
  Date xmas(25, 12, 1990);          // abbreviated form of the above
  // Date my_birthday;              // error: initializer required
  // Date release_date();           // error: most vexing parse
  // Date release_date1(10, 12);    // error: no matching constructor
}

void use_initializer_list() {
  Date today{23, 6, 1986};          // call the constructor
  Date xmas{25, 12, 1990};          // abbreviated form of the above
  // Date release1_0{10, 12};       // error: no matching constructor
}

void call_overloaded_constructors() {
  Date today{4};                    // 4, today's month and year
  Date july4{"July 4, 1983"};       // convert string to date
  Date guy{5, 11};                  // 5, 11, today's year
  Date now;                         // default initialized as today
  Date start{};                     // default initialized as today
}

int main() {
  std::cout << "Hello World!\n";
}
