// C0803_unions.cpp 
#include <iostream>

enum Type { str, num };

struct Entry {
  char* name;
  Type t;
  char* s;    // use s if t == str
  int i;      // use i if t == num
};

void use_entry_struct(Entry* p) {
  if(p->t == str) {
    std::cout << "string: " << p->s << '\n';
  }
  else {
    std::cout << "number: " << p->i << '\n';
  }
}

union Value {
  char* s;    // use s if t == str
  int i;      // use i if t == num
};

struct Entry2 {
  char* name;
  Type t;
  Value v;    // use v.s if t == str, use v.i if t == num
};

void use_entry_union(Entry2* p) {
  if(p->t == str) {
    std::cout << "string: " << p->v.s << '\n';
  }
  else {
    std::cout << "number: " << p->v.i << '\n';
  }
}

union Fudge {
  int i;
  int* p;
};

int* cheat(int i) {
  Fudge a;
  a.i = i;
  return a.p;
}

int* cheat2(int i) {
  return reinterpret_cast<int*>(i);
}

int main() {
  char n[] = "entry1";
  char str[] = "hello";
  Entry e1 = { n, Type::str, str, 10 };
}
