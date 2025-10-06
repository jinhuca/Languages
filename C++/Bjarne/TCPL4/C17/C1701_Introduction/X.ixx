export module X;

export class X {
public:
  X(int);                   // "ordinary constructor": create an object
  X();                      // default constructor
  X(const X&);              // copy constructor
  X(X&&);                   // move constructor
  X& operator=(const X&);   // copy assignment: clean up target and copy
  X& operator=(X&&);        // move assignment: clean up target and move
  ~X();                     // destructor: clean up
  // ...
private:
  int data;
};

X::X(int i) : data{ i } {}
X::X() : data{ 0 } {}
X::X(const X& x) : data{ x.data } {}
X::X(X&& x) : data{ x.data } { x.data = 0; }
X& X::operator=(const X& x) { data = x.data; return *this; }
X& X::operator=(X&& x) { data = x.data; x.data = 0; return *this; }
X::~X() {}
