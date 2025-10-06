// C17030403_Direct_Copy_Initialization.cpp 
import std;

void f() {
  std::vector<std::vector<double>> vs = {
    { 10, 11, 12, 13 },               // OK: vector of four elements
    { 10 },                           // OK: vector of one element
    //10,                               // error: vector<double>(int) is explicit

    std::vector<double>{ 10, 12, 14 },  // OK: vector of four elements
    std::vector<double>{ 10 },          // OK: vector of one element
    std::vector<double>(10)       // OK: vector of 10 elements with value 0.0
  };
}

int main() {
  std::cout << "Hello World!\n";
}
