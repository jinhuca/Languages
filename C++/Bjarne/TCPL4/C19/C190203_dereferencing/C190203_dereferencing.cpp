// C190203_dereferencing.cpp 
#include <iostream>
#include <string>
using std::string;

struct X {
  int a, b;
} x1;

class Ptr {
private:
  X data;
  // ...
public:
  Ptr(X);
  X* operator->();
};

Ptr::Ptr(X x) : data{x} {
}

X* Ptr::operator->() {
  return &data;
}

void f(Ptr p) {
  std::cout << p->a << " & " << p->b << '\n';
}


template<typename T>
void write_to_disk(T* p, const string& id) {
  // simulate writing back to disk and free memory
  delete p;
}

template<typename T>
T* read_from_disk(const string& id) {
  auto res = new T();
  return res;
}

template<typename T>
class Disk_ptr {
  string identifier;
  T* in_core_address;
public:
  Disk_ptr(const string& s) :identifier{s}, in_core_address{nullptr} {}
  ~Disk_ptr() { write_to_disk<T>(in_core_address, identifier); }
  T* operator->() {
    if(in_core_address == nullptr)
      in_core_address = read_from_disk<T>(identifier);
    return in_core_address;
  }
};

struct Rec {
  string name;
  // ...
};

void update(const string& s) {
  Disk_ptr<Rec> p{s};         // get Disk_ptr for s
  p->name = "Roscoe";         // update s; if necessary, first retrieve from disk
  // ...
                              // p's destructor writes back to disk
}

int main() {
  Ptr p1{{1, 2}};
  f(p1);
  update("hello");
}

