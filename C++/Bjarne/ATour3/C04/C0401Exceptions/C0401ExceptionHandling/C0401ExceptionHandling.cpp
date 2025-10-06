// C0401ExceptionHandling.cpp Exception samples
import Vector;
import std;

void f() {
  Vector v1(5);
  std::cout << v1[-9] << '\n';
}

void g() {
  try {
    f();
  }
  catch(std::out_of_range& e) {
    std::cerr << "exception handled in calling g()\n";
    std::cerr << e.what() << '\n';
  }
}

int main() {
  try {
    g();
  }
  catch(std::out_of_range& e) {
    std::cerr << "exception handled in main\n";
    std::cerr << e.what() << '\n';
  }
}
