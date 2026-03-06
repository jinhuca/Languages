// C0804_enumerations.cpp 
#include <iostream>

enum class Color { red, green, blue };  // "Color" is the name of the enum class type
enum Light { red, yellow, green };      // "Light" is the name of the enum type

void use_enum_class() {
  std::cout << "initialization of enum class value.\n";
  // int a1 = red;  // error: red not in scope
  // int a2 = Color::red;  // error: no Color->int conversion
  Color a3 = Color::red;  // OK

  std::cout << "conversion from enum class value to its underlying value.\n";
  // int an_enum_value = Color::red;  // error: no Color->int conversion
  int an_enum_value2 = static_cast<int>(Color::red);  // OK
  auto an_enum_value3 = static_cast<std::underlying_type_t<Color>>(Color::green);  // OK

  std::cout << "conversion from underlying value to enum class value.\n";
  Color a4 = static_cast<Color>(1);  // OK
  Color a5 = static_cast<Color>(8);  // OK, but 8 is not a valid Color value
}

void use_plain_enum() {
  int a1 = red;  // OK
  int a2 = Light::red;  // OK
  Light a3 = red;  // OK
}

int main() {
  use_enum_class();
  use_plain_enum();
}
