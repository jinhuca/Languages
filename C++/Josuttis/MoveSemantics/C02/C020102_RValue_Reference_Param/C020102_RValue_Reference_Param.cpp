import std;

std::string return_string_by_value() {
  return "world";
}

// rvalue reference takes only objects are indicated/marked 
// as programmer no longer need the value
void foo(std::string&& rv) {  
  //rv.push_back('c');   // fixed: use push_back to append a single char
  rv.pop_back();
  std::cout << rv << '\n';
}

void f() {
  std::string s{ "hello" };
  //foo(s);                           // Error: no implicit conversion from lvalue ref to rvalue ref
  foo(std::move(s));                  // OK: marked with std::move on object to say I don't need it
  foo(return_string_by_value());      // OK: temporary return object can be casted to rvalue reference
}

int main() {
  f();
}
