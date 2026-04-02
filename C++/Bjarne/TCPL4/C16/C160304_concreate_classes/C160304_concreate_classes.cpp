// C160304_concreate_classes.cpp 
#include <iostream>

class Date {
};

class Time {
};

class Date_and_time {
private:
  Date d;
  Time t;
public:
  Date_and_time() {}    // default constructor
  Date_and_time(Date dd, Time tt) : d{dd}, t{tt} {}    // constructor from Date and Time
};

int main() {
  
}
