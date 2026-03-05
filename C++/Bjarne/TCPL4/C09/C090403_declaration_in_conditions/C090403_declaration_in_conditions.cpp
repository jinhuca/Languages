// C0943_Declaration_in_conditions.cpp 
import std;


double prim(bool cond) {
  return cond ? 2.1 : -3.2;
}

void f(bool c) {
  if(double d = prim(c)) {
    std::cout << "true for d = " << d << '\n';
  }
  else {
    std::cout << "false for d = " << d << '\n';
  }
}

int main() {
  f(false);
}
