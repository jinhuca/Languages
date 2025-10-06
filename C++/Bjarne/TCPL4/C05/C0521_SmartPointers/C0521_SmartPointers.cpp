// C0521_SmartPointers.cpp
import std;

struct X {
  X() : index { 0 } {}
  X(int e) : index { e } {}
  int index;
  void do_something(){}
};

struct Z {};

void f(int i, int j) {    // X* vs std::unique_ptr<X>
  X* p = new X;                       // allocate a new X on heap
  std::unique_ptr<X> sp { new X };    // allocate a new X and give its pointer to unique_ptr sp
  // ...
  if (i < 99) throw Z {};             // may throw an exception
  if (j > 77) return;                 // may return "early"
  p->do_something();                  // may throw an exception
  sp->do_something();                 // may throw an exception
  // ...
  delete p;                           // destroy *p
}

void f_no_pointer(int i, int j) {
  X x;
  // ...
}

std::unique_ptr<X> make_X(int i) {
  return std::unique_ptr<X>{new X { i }};
}

void f(std::shared_ptr<std::fstream>) {}
void g(std::shared_ptr<std::fstream>) {}

void user(const std::string& name, std::ios_base::openmode mode) {
  std::shared_ptr<std::fstream> fp { new std::fstream(name, mode) };
  if (!*fp) throw std::exception();   // make sure the file was properly opened.

  f(fp);
  g(fp);
  // ...
}

int main() {
  std::cout << "Hello World!\n";
}
