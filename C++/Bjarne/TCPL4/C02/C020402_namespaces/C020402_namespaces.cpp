// C020402_namespaces.cpp 
import std;

namespace My_code {
  class complex{};
  //complex sqrt(complex);
  // ...
  int main();
}

int My_code::main() {
  std::cout << "calling My_code::main().\n";
  return 0;
}

int main() {
  My_code::main();
}
