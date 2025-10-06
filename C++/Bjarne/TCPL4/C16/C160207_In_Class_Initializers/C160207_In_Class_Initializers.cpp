// C160207_In_Class_Initializers.cpp 
import std;

struct { int d, m, y; } date_initializer = {1, 1, 1970};

class Date {
  int d {date_initializer.d};
  int m {date_initializer.m};
  int y {date_initializer.y};
public:
  Date(int, int, int);
  Date(int, int);
  Date(int);
  Date();
};

Date::Date(int dd) :d {dd} {}

void f() {
  Date d1 {12};
}

int main() {
  f();
}
