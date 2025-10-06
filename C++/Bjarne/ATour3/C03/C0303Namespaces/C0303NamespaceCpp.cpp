// C0303NamespaceCpp.cpp
#include <iostream>

namespace my_namespace {
  class complex {
  };

  int main()
  {
    std::cout << "my_namespace main completed.\n";
    return 0;
  }
}
int main() {
  my_namespace::main();
}
