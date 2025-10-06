// C0201_RValue_Reference.cpp 
import std;

std::string returnStringByValue() {
  return "Hello, World!";
}

void f() {
  std::string s { "hello" };
  //std::string&& r1 { s };                     // Error
  std::string&& r1 { returnStringByValue() };   // OK
  std::string&& r2 { std::move(s) };            // OK
  std::string&& r3 { returnStringByValue() };   // OK
}

int main() {
  f();
}
