// C170203_base_and_member_destructors.cpp 
#include <string>
using std::string;

struct S1 {
  string s;
};

struct X { X(int); };
struct S2 {
  X x;
};

int main() {
  S1 s;       // OK: x.s is initialized to "" by the default constructor
  S2 x1;      // error: no default constructor for S2
  S2 X2{1};   // OK: X2.x is initialized by X(int)
}
