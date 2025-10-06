// C030103_Uniform_Init.cpp
import std;

void uniform_init_objects() {
  int i;     // i has undefined value
  int j{};   // j is initialized by 0   
  int* p;    // p has undefined value
  int* q{};  // q is initialized by nullptr
}

void uniform_init_collection() {
  int values[]{ 1,2,3 };
  std::vector<int> v{ 2,3,5,7,11 };
  std::vector<std::string> cities{ "Berlin", "New York", "London" };
  std::complex<double> c{ 4.2,5.2 };
}

void narrow_init() {
  int x1(5.3);// OK, but OUCH: x1 becomes 5
  int x2 = 5.3;  // OK, but OUCH: x2 becomes 5
  //int x3{ 5.0 };  // ERROR: narrowing is not allowed in uniform initialization
  //int x4 = 5.3;   // ERROR: narrwoing
  char c1{ 7 };   // OK: even though 7 is an int, this is not narrowing
  //char c2{ 9999 };  // ERROR: narrowing
  std::vector<int> v1{ 1,2,3,4 };  // OK
  //std::vector<int> v2{ 1,2.3,4.1 };  // ERROR: narrowing
}

int main() {
  uniform_init_objects();
  uniform_init_collection();
  narrow_init();
}
