// C020101.cpp : auto for parameters of member functions
import std;

class MyType {
  void assign(const auto& newValue) { // OK: C++20
    value = newValue;
  }
private:
  int value;
};

int main() {
  std::cout << "Hello World!\n";
}
