// C020200_Std_Move.cpp 
import std;

// binds to the passed object without modifying it.
void foo1(const std::string& lr) {
  std::cout << "lvalue reference.\n";
}

// binds to the passed object and might steal/modify the value.
void foo1(std::string&& rr) {
  std::cout << "rvalue reference.\n";
}

void g() {
  std::string s{ "hello" };
  foo1(s);
  foo1(std::move(s));   
  foo1(static_cast<decltype(s)&&>(s));
}

int main() {
  g();
}
