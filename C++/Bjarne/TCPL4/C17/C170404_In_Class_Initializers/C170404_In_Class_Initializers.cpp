// C170404_In_Class_Initializers.cpp
import std;

class B {
public:
  int a { 7 };
  int b = 77;
  B() :a { 7 }, b { 77 } { }
};

void f() {
  B a1;
}

class A {
public:
  A() :a { 7 }, b { 5 }, state { "run" } { }
  A(int a_value) :a(a_value), b { 5 }, state { "run" } { }
private:
  int a, b;
  //HashFunction algorithm;
  std::string state;
};

int main() {

}
