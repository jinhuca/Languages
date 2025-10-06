// P007.cpp : Arithmetic
import std;

void doArithmeticOpsOnIntegers(const int x, const int y) {
  std::cout << "Do arithmetic operations:" << '\n';
  std::cout << x << " + " << y << " = " << x + y << '\n';
  std::cout << "+" << x << " = " << +x << '\n';
  std::cout << x << " - " << y << " = " << x - y << '\n';
  std::cout << x << " * " << y << " = " << x * y << '\n';
  std::cout << x << " / " << y << " = " << x / y << '\n';
  std::cout << x << " % " << y << " = " << x % y << '\n';
  std::cout << '\n';
}

void doComparisonOnIntegers(const int x, const int y) {
  std::cout << "Do comparison operations:" << '\n';
  std::cout << x << " == " << y << " is " << (x == y) << '\n';
  std::cout << x << " != " << y << " is " << (x != y) << '\n';
  std::cout << x << " < " << y << " is " << (x < y) << '\n';
  std::cout << x << " > " << y << " is " << (x > y) << '\n';
  std::cout << x << " <= " << y << " is " << (x <= y) << '\n';
  std::cout << x << " >= " << y << " is " << (x >= y) << '\n';
  std::cout << '\n';
}

void doLogicalOpsOnIntegers(const int x, const int y) {
  std::cout << "Do logical operations:" << '\n';
  std::cout << (x & y) << '\n';
  std::cout << (x | y) << '\n';
  std::cout << (x ^ y) << '\n';
  std::cout << (~x) << '\n';
  std::cout << (x && y) << '\n';
  std::cout << (x || y) << '\n';
  std::cout << !x << '\n';
  std::cout << '\n';
}

void doBitwiseOps(const int x, const int y) {
  std::cout << "Do bitwise operations:\n";
  std::cout << x << " & " << y << " = " << (x & y) << '\n';
  std::cout << x << " | " << y << " = " << (x | y) << '\n';
  std::cout << x << " ^ " << y << " = " << (x ^ y) << '\n';
  std::cout << "~" << x << " = " << (~x) << '\n';
  std::print("{:X}", 13);
}

void doModification(int x, const int y) {
  std::cout << "Do modification operations:" << '\n';
  std::cout << (x += y) << '\n';
  std::cout << (++x) << '\n';
  std::cout << (x -= y) << '\n';
  std::cout << (--x) << '\n';
  std::cout << (x *= y) << '\n';
  std::cout << (x /= y) << '\n';
  std::cout << (x = x % y) << '\n';
  std::cout << '\n';
}

// function that doesn't return a value
void some_function() {
  double d = 2.2;         // initialize floating-point number
  int i = 7;              // initialize integer
  d = d + i;              // assign sum to d
  i = d * i;              // assign product to i; beware: truncating the double d*i to an int
}

int main() {
  //doArithmeticOpsOnIntegers(12, 32);
  //doComparisonOnIntegers(2, 3);
  //doLogicalOpsOnIntegers(2, 3);
  //doBitwiseOps(11, 13);
  doModification(4, 3);
}
