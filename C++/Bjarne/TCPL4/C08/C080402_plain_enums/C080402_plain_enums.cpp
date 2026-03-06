// C080402_plain_enums.cpp 
#include <iostream>

enum Traffic_light { tl_red, tl_yellow, tl_green };
enum Warning { green, yellow, orange, red };

void use_plain_enum() {
  // Warning a1 = 7;  // error: no int->Warning conversion
  int a2 = green;  // OK, green is in scope and converts to int
  int a3 = Warning::green;  // OK, Warning::green is in scope and converts to int
  Warning a4 = Warning::green;  // OK, Warning::green is in scope and converts to Warning
}

void f(Traffic_light x) {
  if(x == 9) {/* */ }                         // OK, 9 converts to Traffic_light, but is not a valid value
  if(x == tl_red) { /* */ }                   // OK, red is in scope and converts to Traffic_light
  if(x == Warning::red) { /* */ }             // OK, Warning::red is in scope and converts to Traffic_light, but is not a valid value
  if(x == Traffic_light::tl_red) { /* */ }    // OK, Traffic_light::tl_red is in scope and converts to Traffic_light
}

enum E1 { dark, light };                      // range 0:1
enum E2 { a = 3, b = 9 };                     // range 0:15
enum E3 { min = -10, max = 1000000 };         // range -10:1000000

enum Flag { x = 1, y = 2, z = 4, e = 8 };     // range 0:15, but only 1, 2, 4, 8 are valid values

void g() {
  Flag f0 {};  // default initialization, f0 is initialized to 0, which is not a valid Flag value
  //Flag f1 = 5;  // type error, 5 is not of type Flag.
  //Flag f2 = Flag { 5 };  // f2 is initialized to 5, which is not a valid Flag value, but this is not a type error because 5 converts to Flag
  Flag f3 = static_cast<Flag>(5);  // f3 is initialized to 5, which is not a valid Flag value, but this is not a type error because 5 converts to Flag
  Flag f4 = static_cast<Flag>(z | e);  // f4 is initialized to 12, which is not a valid Flag value, but this is not a type error because 12 converts to Flag
  Flag f5 = static_cast<Flag>(99);  // f5 is initialized to 99, which is not a valid Flag value, but this is not a type error because 99 converts to Flag
}

int main() {
  g();
}
