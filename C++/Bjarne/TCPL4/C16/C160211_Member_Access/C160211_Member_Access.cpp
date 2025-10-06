// C160211_Member_Access.cpp 
import std;

struct X {
  void f();
  int m;
};

void f(X x, X* px) {
  x.m = 1;
  px->m = 2;
  px->f();
}

struct S {
  int m;
  int f();
  static int sm;
};

int S::f() { return m; }
int S::sm { 7 };
int(S::* pmf)()(&S::f);   // pointer to S's member function f

int main() {
  
}
