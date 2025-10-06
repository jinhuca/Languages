// C0841_enum_classes.cpp 
import std;

enum class Traffic_light { red, yellow, green };
enum class Warning : char { green, yellow, orange, red };

// Warning a1 = 7;              // error: no int->Warning conversion
// int a2 = green;              // error: green not in scope
// int a3 = Warning::green;     // error: no Warning->int conversion
Warning a4 = Warning::green;    // OK

void f(Traffic_light x) {
  // if(x) { /* ... */ }                      // error: no implicit enum comparison with 0
  // if (x == 9) { /* ... */ }                // error: 9 is not a Traffic_light
  // if (x == red){ /* ... */ }               // error: no red in scope
  // if(x == Warning::red) { /* ... */ }      // error: x is not a Warning enumerator
  if(x == Traffic_light::red) { /* ... */ }   // OK
}

void size_of_enums() {
  std::cout << "size of Warning enum class:\t" << sizeof(Warning) << '\n';
  std::cout << "value of Warning::green:\t" << static_cast<char>(Warning::green) << static_cast<int>(Warning::green) << '\n';
  std::cout << "value of Warning::yellow:\t" << static_cast<char>(Warning::yellow) << static_cast<int>(Warning::yellow) << '\n';
  std::cout << "value of Warning::red:\t" << static_cast<char>(Warning::red) << static_cast<int>(Warning::red) << '\n';
}

void g(Warning key) {
  switch(key) {
  case Warning::green:
    break;
  case Warning::yellow:
    break;
  case Warning::orange:
    break;
  case Warning::red:
    break;
  default:
    ;
  }
}

enum class Printer_flags {
  none = 0,
  acknowledge = 1,
  paper_empty = 2,
  busy = 4,
  out_of_black = 8,
  out_of_color = 16,
  // ...
};

constexpr Printer_flags operator|(Printer_flags a, Printer_flags b) {
  return static_cast<Printer_flags>(static_cast<int>(a) | static_cast<int>(b));
}

constexpr Printer_flags operator&(Printer_flags a, Printer_flags b) {
  return static_cast<Printer_flags>(static_cast<int>(a) & static_cast<int>(b));
}

void try_to_print(Printer_flags x) {
  switch(x) {
  case Printer_flags::none:
    break;
  case Printer_flags::acknowledge:
    break;
  case Printer_flags::paper_empty:
    break;
  case Printer_flags::busy:
    break;
  case Printer_flags::out_of_black:
    std::cout << "out of black.\n";
    break;
  case Printer_flags::out_of_color:
    std::cout << "out of color.\n";
    break;
  case Printer_flags::out_of_black | Printer_flags::out_of_color:
    std::cout << "out of ink, either black or color.\n";
    break;
  }
}

enum class Flag :char { x = 1, y = 2, z = 4, e = 8 };

void convert_enum() {
  Flag f0 {};                             // f0 gets the default value 0
  //Flag f1 = 5;                          // type error: 5 is not of type Flag
  Flag f2 = Flag { 5 };                   // error: no narrowing conversion to an enum class
  Flag f3 = static_cast<Flag>(5);         // bruce force
  Flag f4 = static_cast<Flag>(999);       // error: 999 is not a char value (maybe not caught)
}

void extract_enum_value() {
  int i = static_cast<int>(Flag::y);      // enum underlying type is only integral type:
  char c = static_cast<char>(Flag::e);    // int or char
  // std::string s = static_cast<std::string>(Flag::e);
}

int main() {
  //size_of_enums();
  //try_to_print(Printer_flags::out_of_black | Printer_flags::out_of_color);
  convert_enum();
  extract_enum_value();
}
