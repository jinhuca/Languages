// C080401_enum_classes.cpp 
#include <iostream>

enum class Color { red, green, blue };  // "Color" is the name of the enum class type
enum class Traffic_light { red, yellow, green };  // "Traffic_light" is the name of the enum class type
enum class Warning { green, yellow, red };  // fire alert levels

void use_enum_class1() {
  // Warning a1 = 7;  // error: no int->Warning conversion
  // int a2 = green;  // error: green not in scope
  // int a3 = Warning::green;  // error: no Warning->int conversion
  Warning a4 = Warning::green;  // OK
}

void use_enum_class2(Traffic_light x) {
  // if(x == 9) {/* */ }                  // error: no int->Traffic_light conversion
  // if(x == red) { /* */ }               // error: red not in scope
  // if(x == Warning::red) { /* */ }      // error: no Warning->Traffic_light conversion
  if(x == Traffic_light::red) { /* */ }   // OK
}

enum class Printer_flags {
  acknowledge = 1,
  paper_empty = 2,
};

int main() {
  use_enum_class1();
  use_enum_class2(Traffic_light::yellow);
}
