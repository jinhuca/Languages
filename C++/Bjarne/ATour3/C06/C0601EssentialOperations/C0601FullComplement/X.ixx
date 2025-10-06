export module X;
import std;

export class X {
public:
  // default constructor
  X() {
    sz = 1;
    elem = new int[1];
    std::cout << "X default constructor.\n";
  }
  // ordinary constructor
  X(int s) {
    sz = s;
    elem = new int[s];
    std::cout << "X ordinary constructor.\n";
  }
  // copy constructor
  X(const X& a) {
    sz = a.sz;
    elem = new int[a.sz];
    for(auto i = 0; i != a.sz; ++i)
      elem[i] = a.elem[i];
    std::cout << "X copy constructor.\n";
  }
  // move constructor
  X(X&& b) {
    sz = b.sz;
    elem = new int[b.sz];
    for(auto i = 0; i != b.sz; ++i)
      elem[i] = b.elem[i];
    b.sz = 0;
    b.elem = nullptr;
    std::cout << "X move constructor.\n";
  }
  // copy assignment: clean up target and copy
  X& operator=(const X& x) {
    delete[] elem;
    sz = x.sz;
    elem = new int[x.sz];
    for(auto i = 0; i != x.sz; ++i) {
      elem[i] = x.elem[i];
    }
    std::cout << "X copy assignment.\n";
    return *this;
  }
  // move assignment: clean up target and move
  X& operator=(X&& x) {
    delete[] elem;
    sz = x.sz;
    elem = new int[x.sz];
    for(auto i = 0; i != x.sz; ++i) {
      elem[i] = std::move(x.elem[i]);
    }
    x.elem = nullptr;
    x.sz = 0;
    std::cout << "X move assignment.\n";
    return *this;
  }
  ~X() {
    delete[] elem;
    std::cout << "X destructor.\n";
  }
  int size() const {
    return sz;
  }
private:
  int* elem;
  int sz;
};