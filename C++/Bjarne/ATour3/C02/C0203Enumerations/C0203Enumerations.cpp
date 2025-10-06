// C0203Enumerations.cpp : 

import std;

enum class Color { red, blue, green };
enum class Traffic_light { green, yellow, red };

Color col = Color::red;
Traffic_light light = Traffic_light::red;

std::string toString(Color& c) {
  switch(c) {
  case Color::blue:
    return "blue";
  case Color::green:
    return "green";
  case Color::red:
    return "red";
  default:
    return "unknown";
  }
}

int main() {
  std::cout << static_cast<int>(light) << '\n';
  std::cout << (int)col << '\n';
  std::cout << toString(col) << '\n';
}
