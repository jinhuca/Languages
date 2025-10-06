// P005.cpp
import std;


void print(int) {}            // takes an integer argument
void print(double) {}         // takes a floating-point argument
void print(std::string) {}    // takes a string argument

void user() {
  print(42);                  // calls print(int)
  print(9.65);                // calls print(double)
  print("Barcelona");         // calls print(string)
}

void print(int, double) {}
void print(double, int) {}

void user2() {
  print(0, 0);                  // error: ambiguous
  print((int)0, (double)1.2);   // specify argument types
}

int main() {
  user();
}
