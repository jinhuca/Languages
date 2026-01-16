// C0101_BindingDetails.cpp 
import std;

struct MyStruct {
  int i = 0;
  std::string s;
};

void f() {
  MyStruct ms { 42, "hello" };
  auto [u, v] = ms;

  ms.i = 77;
  std::cout << u << '\n';
  u = 99;
  std::cout << ms.i << '\n';
}

void g() {
  MyStruct ms { 43, "hello" };
  const auto& [u, v] {ms};
  std::cout << u << ", " << v << '\n';
  ms.i = 1;
  std::cout << u << ", " << v << '\n';
}

void h() {
  MyStruct ms = { 42, "Jim" };
  auto&& [v, n] = std::move(ms);
  std::cout << ms.i << " : " << ms.s << '\n';

  std::string s = std::move(n);
  std::cout << "ms.s:  " << ms.s << '\n';
  std::cout << "n:     " << n << '\n';
  std::cout << "s:     " << s << '\n';
}

void j() {

}

int main() {
  //g();
  h();
}
