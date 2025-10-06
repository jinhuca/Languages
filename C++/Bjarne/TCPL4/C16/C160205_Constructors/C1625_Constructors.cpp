// C1625_Constructors.cpp 
import std;

class Date {
  int d, m, y;
public:
  Date(int dd, int mm, int yy);   // initialize with day, month, and year
  Date(int dd, int mm);           // day, month, today's year
  Date(int dd);                   // day, today's month and year
  Date();                         // default date: today
  Date(const char*);              // date in string representation
  // ...
};

Date::Date(int dd, int mm, int yy) {
  d = dd;
  m = mm;
  y = yy;
}

Date::Date() {
  d = 0;
  m = 0;
  y = 0;
}

Date::Date(int dd, int mm) {
  d == dd;
  m = mm;
}

Date::Date(int dd) {
  d = dd;
}

Date::Date(const char*) {

}

void call_constructor() {
  Date today = Date(23, 6, 1983);
  Date Xmas(25, 12, 1991);       // abbreviated form
  // Date my_birthday;                       // error: initializer missing
  // Date release1_0(10, 12);                // error: third argument missing
}

void initializer_call() {
  Date today = Date { 23,6,1983 };
  Date Xmas { 25, 12, 1991 };       // abbreviated form
}

void call_overloaded_constructors() {
  Date today { 4 };
  Date july4 { "July 4, 1983" };
  Date guy { 5,11 };
  Date now;
  Date start {};
}

int main() {
  //call_constructor();
  //initializer_call();
  call_overloaded_constructors();
}
