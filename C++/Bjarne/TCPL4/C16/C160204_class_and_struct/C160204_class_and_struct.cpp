// C160204_class_and_struct.cpp 
#include <iostream>

class Date1 {
  int d, m, y;                      // private by default
public:
  Date1(int dd, int mm, int yy);    // constructor
  void add_year(int n);             // add n years
};

class Date2 {
private:
  int d, m, y;                      // private by default
public:
  Date2(int dd, int mm, int yy);    // constructor
  void add_year(int n);             // add n years
};

class Date3 {
public:
  Date3(int dd, int mm, int yy);    // constructor
  void add_year(int n);             // add n years
private:
  int d, m, y;                      // private by default
};

class Date4 {
public:
  Date4(int dd, int mm, int yy);    // constructor
private:
  int d, m, y;                      // private by default
public:
  void add_year(int n);             // add n years
};

int main() {
  
}
