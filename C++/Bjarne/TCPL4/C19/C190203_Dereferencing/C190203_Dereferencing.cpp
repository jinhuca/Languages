// C190203_Dereferencing.cpp 
import std;
import Disk_ptr;

struct X {
  int x, y;
};

class Ptr {
  X data;
  // ...
public:
  Ptr(X a) :data { a } {};
  X* operator->() { return &data; }
};

void f(Ptr p) {
  X* x1 = p.operator->();
  std::cout << p->x << " - " << p->y << '\n';
  p->x = 7;
  p->y = 9;
  std::cout << p->x << " - " << p->y << '\n';
}

void update(const std::string& s) {
  Disk_ptr<Rec> p { s };    // get Disk_ptr for s
  p->name = "Roscoe";       // update s
}

int main() {
  Ptr p { X{1,2} };
  f(p);
}
