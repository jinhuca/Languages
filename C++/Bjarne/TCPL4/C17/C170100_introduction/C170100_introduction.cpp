// C170100_introduction.cpp 
#include <string>
using std::string;

class Sometype {
  // ...
};

class X {
public:
  X(Sometype);                // "ordinary constructor": create an X from a Sometype
  X();                        // default constructor
  X(const X&);                // copy constructor: create an X from an X
  X(X&&);                     // move constructor: create an X from an X that is about to be destroyed;
  X& operator=(const X&);     // copy assignment: clean up target and copy
  X& operator=(X&&);          // move assignment: clean up target and move
  ~X();                       // destructor: clean up an X that is about to be destroyed
};

string ident(string arg) {    // string passed by value (copied into arg)
  return arg;                 // return string (move the value of arg out of ident() to the caller)
}

int main() {
  string s1{"Adams"};         // initialize string (construct in s1),
  s1 = ident(s1);             // copy s1 into arg, 
                              // then move the result of ident(s1) into s1,
                              // s1's value is "Adams"
  string s2{"Pratchett"};     // initialize string (construct in s2),
  s1 = s2;                    // copy the value of s2 into s1, 
                              // both s1 and s2 have the value "Pratchett".
}
