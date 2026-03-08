// C1002_desk_calculator.cpp
//import std;
#include <iostream>
#include <sstream>

#include "Token.h"
#include "Token_stream.h"
#include "Utilities.h"
#include "Parser.h"
#include "Symbols.h"

void calculate() {
  for(;;) {
    ts.get();
    if(ts.current().kind == Kind::end) break;
    if(ts.current().kind == Kind::print) continue;
    std::cout << expr(false) << '\n';
  }
}

int main(int arg, char* argv[]) {
  initialize_symbol_table();
  switch(arg) {
  case 1:
    break;
  case 2:
    ts.set_input(new std::istringstream { argv[1] });
    break;
  default:
    error("too many arguments");
    return 1;
  }
  calculate();
  return no_of_errors;
}
