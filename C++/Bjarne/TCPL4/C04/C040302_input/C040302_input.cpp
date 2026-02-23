// C0432_Input.cpp
import std;

void simple_ostream_demo() {
  int i;
  std::cin >> i;
  double d;
  std::cin >> d;
}

void hello() {
  std::cout << "Please enter your name\n";
  std::string str;
  std::cin >> str;
  std::cout << "Hello, " << str << "!\n";
}

void hello_line()
{
  std::cout << "Please enter your name\n";
  std::string str;
  std::getline(std::cin, str);
  std::cout << "Hello, " << str << "!\n";
}
int main() {
  //f();
  //hello();
  hello_line();
}