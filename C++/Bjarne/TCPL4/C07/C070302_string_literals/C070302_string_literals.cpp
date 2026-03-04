// C0732_String_literals.cpp
import std;

void size_of_string_literal() {
  std::cout << sizeof("hello") << '\n';           // 6: 5 characters + null terminator
}

void type_of_string_literal() {
  std::cout << typeid("hello").name() << '\n';    // const char [6]
  std::cout << typeid(decltype("hello")).name() << '\n';  // const char [6]
  // char* p = "hello";     // error: cannot convert const char* to char*
  const char* q = "hello";  // ok: string literals are of type const char[]
  auto r = "hello";         // r is of type const char[6]
  std::cout << typeid(r).name() << '\n';    // const char [6], which decays to const char* when used in most expressions
}

void mutable_array_of_chars() {
  char p[] = "zeno";
  p[0] = 'R';
  const char* r = "";
}

const char* p = "hello";
const char* q = "hello";

void compare_string_literals() {
  std::cout << "Compare the addresses of two string literals; it's implementation-defined: -\n";
  if (p == q) std::cout << "one!\n";
  else std::cout << "two!\n";

  std::cout << "Compare the contents of two string literals - std::strcmp: -\n";
  if(std::strcmp(p, q) == 0) std::cout << "equal!\n";
  else std::cout << "not equal!\n";

  std::cout << "Compare the contents of two string literals - std::string: -\n";
  if(std::string(p) == q) std::cout << "equal!\n";
  else std::cout << "not equal!\n";

  std::cout << "Compare the contents of two string literals - std::string_view: -\n";
  if(std::string_view(p) == q) std::cout << "equal!\n";
  else std::cout << "not equal!\n";
}

void escaped_characters() {
  std::cout << "Line 1\nLine 2\n";   // \n is a newline character
  std::cout << "Tab\tseparated\n";   // \t is a tab character
  std::cout << "Backslash: \\\n";    // \\ is a backslash character
  std::cout << "Double quote: \"\n";  // \" is a double quote character
  std::cout << "Single quote: \'\n";  // \' is a single quote character
}

void long_string_literals() {
  const char* s = "This is a long string literal "
                  "that spans multiple lines "
                  "in the source code.";
  std::cout << s << '\n';
}

void null_char_in_string_literal() {
  char s[] = "Hello\000World";  // s is an array of 12 chars: 'H', 'e', 'l', 'l', 'o', '\0', 'W', 'o', 'r', 'l', 'd', '\0'
  std::cout << s << '\n';     // prints "Hello" because of the null terminator
  
  std::cout << sizeof(s) << '\n';  // prints 12, the size of the array
  std::cout << std::strlen(s) << '\n';  // prints 5, the length of the string up to the first null terminator
}

int main() {
  size_of_string_literal();
  type_of_string_literal();
  compare_string_literals();
  mutable_array_of_chars();

  long_string_literals();
  if (p == q) std::cout << "one!\n";
  else std::cout << "two!\n";

  std::cout << "beep\a\n";
  const char* s = "fdsalk"
    "dasdas";
  char alpha[] = "fadfk"
    "ewrwl;";

  char al[] = "jens\000munk";
  null_char_in_string_literal();
}
