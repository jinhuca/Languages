// C1701_Introduction.cpp 
import std;
import X;

std::string ident(std::string arg) {    // string passed by value (copied into arg)
  return arg;       // return string (move the value of arg out of ident() to a caller)
}

void f() {
  std::string s1{ "Adams" };          // initialize string (construct in s1).
  s1 = ident(s1);                     // copy s1 into ident()
  // move the result of ident(a1) into s1;
  // s1's value is "Adams".
  std::string s2{ "Pratchett" };      // initialize string (construct in s2)
  s1 = s2;                            // copy the value of s2 into s1
  // both s1 and s2 have the value "Pratchett".
}

void g() {
  X x1{ 7 };               // construct x1 from 7
  X x2{ x1 };              // copy-construct x2 from x1
  X x3{ std::move(x1) };   // move-construct x3 from x1; x1 is now in a valid but unspecified state
  X x4;                    // default-construct x4
  x4 = x2;                 // copy-assign x2 to x4
  // both x2 and x4 have the same value
  x4 = std::move(x3);      // move-assign x3 to x4; x3 is now in a valid but unspecified state
}

int main() {
  f();
  g();
}
