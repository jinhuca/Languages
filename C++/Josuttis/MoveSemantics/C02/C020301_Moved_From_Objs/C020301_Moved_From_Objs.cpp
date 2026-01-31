// C020301_Moved_From_Objs.cpp 
import std;

void foo(std::string&& rs) {
  std::cout << "Passed in rvalue = " << rs << '\n';
}

int main() {
  std::string s{ "hello world" };
  foo(std::move(s));
  
  std::cout << s << '\n';
  std::cout << s.size() << '\n';
  std::cout << s[0] << '\n';
  std::cout << s.front() << '\n';

  s = "new universe";
}
