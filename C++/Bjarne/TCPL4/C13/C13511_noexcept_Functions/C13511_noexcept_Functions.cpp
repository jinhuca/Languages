// C13511_noexcept_Functions.cpp 
import std;

void f(double x) {
  if(x < 0)
    throw std::runtime_error("something wrong...");
  std::cout << "f completed successfully.\n";
}

double compute(double x) noexcept {
  std::string s = "Courtney and Anya";
  std::vector<double> tmp(10);
  // ...
  f(x);
  return s.length();
}

int main() {
  std::cout << compute(-3) << '\n';
}
