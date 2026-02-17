// C020203_constants.cpp 
import std;

constexpr int square(int x) {
  return x * x;
}

int square_non_constexpr(int x) {
  return x * x;
}

void f() {
  const int dmv = 100;                  // dmv is a constant integer, must be initialized at declaration
  //dmv = 200;                          // error: cannot assign to a variable that is const
  int var = 10;                         // var is a non-constant integer, can be modified

  constexpr int max1 = 4 * square(5);   // max1 is a compile-time constant, can be used in contexts that require compile-time constants
  // if square is a constexpr function, max1 can be evaluated at compile time

  const int max2 = 4 * square_non_constexpr(5);   // max2 is a constant integer, but since square_non_constexpr is not a constexpr function, 
  // max2 cannot be evaluated at compile time
}

constexpr int sum(std::vector<int> v) {
  int s = 0;
  for (int i : v) {
    s += i;
  }
  return s;
}

void g() {
  std::vector<int> v {1, 2, 3, 4, 5};
  //constexpr int total = sum(v);   // error: cannot evaluate sum at compile time because it takes a non-literal type (std::vector<int>) as an argument 
}

void demonstrate_constants() {
  std::cout << "demonstrating constants:\n";
  const int x = 10;   // x is a constant integer, must be initialized at declaration
  //x = 20;           // error: cannot assign to a variable that is const
  std::cout << "x: " << x << '\n';
  const double pi = 3.14159;   // pi is a constant double
  std::cout << "pi: " << pi << '\n';
  const char* message = "Hello, World!";   // message is a pointer to a constant character array (string literal)
  std::cout << "message: " << message << '\n';
  constexpr int max_size = 100;   // max_size is a compile-time constant, can be used in contexts that require compile-time constants
  std::cout << "max_size: " << max_size << '\n';
}

int main() {
  std::cout << "Hello World!\n";
}
