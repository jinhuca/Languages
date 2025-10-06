// C030110_Lambdas.cpp 
import std;

void lambda_def1() {
  [] { std::cout << "hello lambda\n"; }();
}

void lambda_def2() {
  auto lambda = [] {std::cout << "hello lambda\n"; };
  lambda();
}

void lambda_def3(const std::string& param) {
  auto lambda = [](const std::string& s) {
    std::cout << "hello " << s << '\n';
    };
  lambda(param);
}

void capture_variables() {
  int x = 0;
  int y = 42;
  auto qqq = [x, &y] {
    std::cout << "x: " << x << '\n';
    std::cout << "y: " << y << '\n';
    ++y;   // OK
    };
  x = y = 77;
  qqq();
  qqq();
  std::cout << "final y: " << y << '\n';
}

int main() {
  //lambda_def1();
  //lambda_def2();
  //lambda_def3("lambda");
  //auto lambda = [](const std::string& s)->int { return s.size(); };
  //std::cout << lambda("hello lambda");
  capture_variables();
}
