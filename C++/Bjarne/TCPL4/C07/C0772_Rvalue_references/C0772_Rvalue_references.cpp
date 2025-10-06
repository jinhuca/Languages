// C0772_Rvalue_references.cpp
import std;

std::string f() { return "Montreal"; }  // the return value of f() is rvalue (temporary)

void h() {
  std::string var { "Cambridge" };        // var is a lvalue
  std::string& r1 { var };                // lvalue reference, bind r1 to var (a lvalue)
  //std::string& r2 { f() };              // error: lvalue reference - the return value f() is an rvalue
  //std::string& r3 { "Princeton" };      // error: lvalue reference cannot bind to temporary
  std::string&& rr1 { f() };              // fine: rvalue reference to rvalue (temporary)
  //std::string&& rr2 { var };            // error: var is an lvalue
  std::string&& rr3 { "Oxford" };         // OK: rr3 refers to a temporary holding "Oxford"
}

std::string k(std::string&& s) {
  if(s.size())
    s[0] = std::toupper(s[0]);
  return s;
}

template<typename T>
void swap_in_old_way(T& a, T& b) {
  T temp { a };                         // now we have two copies of a
  a = b;                                // now we have two copies of b
  b = temp;                             // now we have two copies of tmp (aka a)
}

template<typename T>
void swap_almost_perfect(T& a, T& b) {
  T tmp { static_cast<T&&>(a) };        // the initialization may write to a
  a = static_cast<T&&>(b);              // the assignment may write to b
  b = static_cast<T&&>(tmp);            // the assignment may  write to tmp
}

template<typename T>
void swap(T& a, T& b) {           // "perfect swap" (almost)
  T tmp { std::move(a) };         // move from a
  a = std::move(b);               // move from b
  b = std::move(tmp);             // move from tmp
}

void swap_demo() {
  std::string s1 { "hello" };
  std::string s2 { "world" };
  swap_in_old_way(s1, s2);
  swap_almost_perfect(s1, s2);
  swap(s1, s2);
}

class record {
public:
  record(int s) : x { s } {}
  record(const record& s) : x { s.x } {
    std::cout << "copy constructor.\n";
  }
  record& operator=(const record& a) {
    std::cout << "copy assignment.\n";
    x = a.x;
    return *this;
  }
  record(record&& s) noexcept : x { s.x }
  {
    std::cout << "move constructor.\n";
    s.x = 0;
  }
  record& operator=(record&& a) {
    x = a.x;
    a.x = 0;
    std::cout << "move assignment.\n";
    return *this;
  }
private:
  int x;
};

void k() {
  record r1(1), r2(2);
  swap(r1, r2);
}

int main() {
  //h();
  //auto s1 = k("john");
  //swap_demo();
  k();
}
