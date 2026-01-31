// C050205_unique_ptr.cpp 
import std;

class ClassA {
public:
  ~ClassA() {
    std::cout << "ClassA destroyed\n";
  }
};

void g() {
  // initialize a unique_ptr with a new object
  std::unique_ptr<ClassA> up1(new ClassA());

  // copy the unique_ptr (not allowed)
  //std::unique_ptr<ClassA> up2 = up1; // ERROR: cannot copy unique_ptr

  // transfer ownership using std::move
  std::unique_ptr<ClassA> up3 = std::move(up1); // OK: ownership transferred
}

void f() {
  // create and initialize (pointer to) string:
  std::unique_ptr<std::string> up(new std::string("nico"));

  (*up)[0] = 'N';     // capitalize first letter
  up->append("lai");  // append some characters
  std::cout << *up << '\n';

  std::string* sp = up.release(); // release ownership
  std::cout << *sp << '\n';
  //std::cout << *up << '\n'; // undefined behavior!
  if (up) {
    std::cout << "up is not null\n";
  }
  else {
    std::cout << "up is null\n";
  }
}

int main() {
  g();
}
