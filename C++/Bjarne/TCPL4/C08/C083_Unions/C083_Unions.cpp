// C083_Unions.cpp 
import std;

enum Type { str, num };

namespace struct_without_union {
  struct Entry {
    char* name;
    Type t;
    char* s;      // use s if t == str
    int i;        // use i if t = num
  };

  void f(Entry* p) {
    if(p->t == str) {
      std::cout << "using str: " << p->s;
    }
    else {
      std::cout << "using int: " << p->i;
    }
    // ...
  }
}

namespace struct_use_union {
  union Value {
    char* s;
    int i;
  };

  struct Entry {
    char* name;
    Type t;
    Value v;    // use v.s if t == str; use v.i if t == num
  };

  void f(Entry* p) {
    if(p->t == str) {
      std::cout << "using str in union: " << p->v.s;
    }
    else if(p->t == num) {
      std::cout << "using int in union: " << p->v.i;
    }

  }
}

void f_struct() {
  char n[] = "John";
  char s[] = "id";
  struct_without_union::Entry e1 = {
    n,
    Type::str,
    s,
    134
  };
  struct_without_union::f(&e1);
}

void f_union() {
  char n[] = "Joe";
  char s[] = "hello";
  struct_use_union::Value v { s };
  struct_use_union::Entry e1 = {
    n,
    Type::str,
    v
  };
  struct_use_union::f(&e1);
}

namespace type_conversion_cheating {
  union Fudge {
    int i;
    int* p;
  };

  int* cheat(int i) {
    Fudge a;
    a.i = i;
    return a.p;     // bad use
  }

  int* cheat2(int i) {
    return reinterpret_cast<int*>(i);     // obviously ugly and dangerous
  }
}

int main() {
  //f_struct();
  //f_union();
  auto x1 = type_conversion_cheating::cheat(123);
  std::cout << *x1 << '\n';
  auto x2 = type_conversion_cheating::cheat2(123);
  std::cout << *x2 << '\n';
}
