#include <iostream>

int main() {
  std::cout << "full namespace qualification\n";

  using std::cout;
  cout << "Hello World with using declaration!\n";

  using namespace std;
  cout << "Hello World with using directive!\n";
}
