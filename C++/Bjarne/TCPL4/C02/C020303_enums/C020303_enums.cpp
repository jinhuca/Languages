// C020303_enums.cpp 
#include <iostream>

enum class Color { red, green, blue };
enum class Traffic_light { green, yellow, red };
Traffic_light& operator++(Traffic_light t) {
  switch(t) {
    case Traffic_light::green: return t = Traffic_light::yellow;
    case Traffic_light::yellow: return t = Traffic_light::red;
    case Traffic_light::red: return t = Traffic_light::green;
  }
}

void g() {
  Traffic_light light {Traffic_light::red};
  Traffic_light next = ++light;
}

void f() {
  // Color x = red;                    // error: which red?
  // Color y = Traffic_light::red;     // error: that red is not a Color
  Color z = Color::red;                // OK

  // int i = Color::red;               // error: Color::red is not int
  int j = static_cast<int>(Color::red);   // OK: explicit conversion from enum class to int
  Color k = static_cast<Color>(2);
  // Color c = 2;                      // error: 2 is not a Color
}

int main() {
  f();
  g();
}
