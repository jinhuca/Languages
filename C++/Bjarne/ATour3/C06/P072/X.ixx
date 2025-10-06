export module X;
#include <algorithm>

export class X {
public:
  X(int);                     // ordinary constructor
  X();                        // default constructor
  X(const X&);               // copy constructor
  X(X&&);                    // move constructor
  X& operator=(const X&);    // copy assignment: clean up target and copy
  X& operator=(X&&);         // move assignment: clean up target and move
  ~X();                       // destructor: clean up
private:
  int m;
};

inline X::X(int x) : m { x } {}
inline X::X() : m { 0 } {}
inline X::X(const X& x) : m { x.m } {}
inline X::X(X&& x) : m { std::move(x.m) } {}

inline X& X::operator=(const X&) {
}

inline X& X::operator=(X&&) {
}

inline X::~X() {
}