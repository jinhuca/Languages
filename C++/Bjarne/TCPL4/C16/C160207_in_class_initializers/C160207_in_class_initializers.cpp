// C160207_in_class_initializers.cpp 
#include <iostream>

// aggregate initialization of an unnamed struct.
struct { int d, m, y; } date_initializer{1, 1, 1970};

class Date {
  int d{date_initializer.d};
  int m{date_initializer.m};
  int y{date_initializer.y};
public:
  Date(int, int, int);      // day, month, year
  Date(int, int);           // day, month, today's year
  Date(int);                // day, today's month and year;
  Date();                   // default Date: today
  Date(const char*);        // date in string representation
  // ... other members
};

int main() {
  Date today;               // 
}
