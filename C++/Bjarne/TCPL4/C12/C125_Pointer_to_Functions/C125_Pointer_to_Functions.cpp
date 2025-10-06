// C125_Pointer_to_Functions.cpp 
import std;

void error(std::string s) { std::cout << s << '\n'; }
void (*efct)(std::string);      // pointer to function taking a string argument and return nothing

void f() {
  efct = error;                // efct points to error function
  efct("error");              // call error through efct
}

void (*f1)(std::string) = &error;
void (*f2)(std::string) = error;

void g() {
  f1("Vasa");               // 
  (*f2)("Mary Rose");       //
}

void (*pf)(std::string);      // pf is a variable of type as pointer to function, which has a std::string as argument, and return nothing.
void h1(std::string s) { std::cout << s << '\n'; };
int h2(std::string s) { return s.length(); }
void h3(int* pi) { std::cout << *pi << '\n'; }

void k() {
  pf = h1;                    // OK
  //pf = h2;                  // error: bad return type
  //pf = &h3;                 // error: bad arguments

  pf("Hera");               // OK
  //pf(1);                    // error: bad argument type

  //int i = pf("Zeus");       // error: void assigned to int
}

namespace conversions {
  using P1 = int(*)(int*);
  using P2 = void(*)(void);

  int f1(int* pi) {
    *pi += 12;
    std::cout << *pi << '\n';
    return *pi;
  }
  void f2() {
    std::cout << "nothing done.\n";
  }

  void f(P1 pf) {
    P2 pf2 = reinterpret_cast<P2>(pf);
    pf2();                                // likely serious problem
    P1 pf1 = reinterpret_cast<P1>(pf2);   // convert pf2 "back again" to pf1
    int x = 7;
    int y = pf1(&x);                      // OK
  }
}

int main() {
  //f();
  //g();
  //k();
  conversions::f(conversions::f1);
}
