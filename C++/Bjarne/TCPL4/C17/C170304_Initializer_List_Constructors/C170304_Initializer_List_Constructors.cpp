// C170304_Initializer_List_Constructors.cpp 
import std;

std::vector<double> vv;

void f() {
  std::vector<double> v = { 1, 2, 3.456, 99.1 };
  std::vector<std::string> languages {
    { "Nygaard", "Simula" }, { "Richards", "BCPL" }, { "Ritchie", "C" }
  };
}

int main() {
  f();
}
