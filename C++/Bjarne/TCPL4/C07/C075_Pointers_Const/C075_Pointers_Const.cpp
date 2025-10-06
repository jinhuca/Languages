// C075_Pointers_Const.cpp
import std;

void f() {
  const int model = 90;           // model is a const
  const int v[] { 1,2,3,4 };      // v[i] is a const
  //const int x;                  // error: no initializer
  //model = 200;                  // error: can't change
  //v[2] = 3;                     // error: can't change
}

struct X {
  int p, q;
};

void g(const X* p) {
  // can't modify *p in this scope
  //p->p = 1;
}

void h(const int* pi) {
  //*pi = 2;
}

void f1(char* p) {
  char s[] = "Gorm";

  const char* pc = s;           // pointer to constant
  //pc[3] = 'g';                  // error: pc points to constant
  pc = p;                       // OK

  char* const cp = s;           // constant pointer
  cp[3] = 'a';                  // OK
  //cp = p;                       // error: cp is constant

  const char* const cpc = s;    // const pointer to const
  //cpc[3] = 'a';                 // error: cpc points to constant
  //cpc = p;                      // error: cpc is constant
  char a = cpc[0];
}

int main() {
  char p1[] = "hello";
  f1(p1);
}
