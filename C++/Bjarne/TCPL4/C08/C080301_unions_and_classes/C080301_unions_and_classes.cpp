// C080301_unions_and_classes.cpp 
#include <iostream>

enum Type { str, num };

union Entry {
  Type t;
  char* s;    // use s if t == str
  int i;      // use i if t == num
};

int main() {
  char n[] = "hello";
  int v = 42;
  Entry e1(Type::str);
  e1.i = v;
  e1.s = n;
}
