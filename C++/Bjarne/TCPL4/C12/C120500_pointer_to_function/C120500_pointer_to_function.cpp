// C120500_pointer_to_function.cpp 
#include <iostream>
#include <string>
using std::cout;
using std::string;

// function taking a string argument and returning nothing
void error(string s) { cout << s << '\n'; }

// pointer to function taking a string argument and returning nothing
void (*efct)(string);

void f() {
  efct = &error;                // efct points to error
  efct("error");                // call error through efct
}

void (*f1)(string) = &error;    // OK: same as = error
void (*f2)(string) = error;     // OK: same as = &error

void g() {
  f1("Vasa");                   // OK: same as (*f1)("Vasa")
  (*f1)("Mary Rose");           // OK: same as f1("Mary Rose")
}

// type match between function and pointer to function
void (*pf)(string);                     // pointer to function with type void(string)
void f11(string s) {                    // function type - void(string)
  cout << "call void f11(string).\n";
}
int f22(string s) {                     // function type - int(string)
  cout << "call int f22(string).\n";
  return 2;
}
void f33(int* i) {                      // function type - void(int*)
  cout << "call void f33(int*).\n";
}

void match_pointer_and_function() {
  pf = &f11;              // OK
  //pf = &f22;            // error: bad return type
  //pf = &f33;            // error: bad argument type

  pf("Hera");             // OK
  //pf(1);                // error: bad argument type

  //int i = pf("Zeus");   // error: void assigned to int
}

using P1 = int(*)(int*);
using P2 = void(*)(void);

void k(P1 pf) {
  P2 pf2 = reinterpret_cast<P2>(pf);
  pf2();                                  // likely serious problem
  P1 pf1 = reinterpret_cast<P1>(pf2);     // convert pf2 "back again"
  int x = 7;
  int y = pf1(&x);                        // OK
}

// take address of overloaded functions
void q(int i) {}
int q(char c) { return 1; }

void (*pf11)(int) = &q;         // void q(int)
int (*pf22)(char) = &q;         // int q(char)
//void (*pf33)(char) = &q;      // error: no void f(char)

int main() {
  f();
  g();
}
