// C1002_desk_calculator.cpp
//import std;
#include <iostream>
#include <sstream>
#include <map>

#include "Token.h"
#include "Token_stream.h"
#include "Utilities.h"

std::map<std::string, double> table;

double expr(bool get);
double term(bool get);
double prim(bool get);

double expr(bool get) {
  double left = term(get);
  for(;;) {
    switch(ts.current().kind) {
    case Kind::plus:
      left += term(true);
      break;
    case Kind::minus:
      left -= term(true);
      break;
    default:
      return left;
    }
  }
}

double term(bool get) {
  double left = prim(get);
  for(;;) {
    switch(ts.current().kind) {
    case Kind::mul:
      left *= prim(true);
      break;
    case Kind::div:
      if(auto d = prim(true)) {
        left /= d;
        break;
      }
      return error("divide by 0");
    default:
      return left;
    }
  }
}

double prim(bool get) {
  if(get) {
    ts.get();
  }

  switch(ts.current().kind) {
  case Kind::number:
  {
    double v = ts.current().number_value;
    ts.get();
    return v;
  }
  case Kind::name:
  {
    double& v = table[ts.current().string_value];
    if(ts.get().kind == Kind::assign) {
      v = expr(true);
    }
    return v;
  }
  case Kind::lp:
  {
    auto e = expr(true);
    if(ts.current().kind != Kind::rp) {
      return error("')' expected");
    }
    void(ts.get());
    return e;
  }
  default:
    return error("primary expected");
  }
}

void calculate() {
  for(;;) {
    ts.get();
    if(ts.current().kind == Kind::end) break;
    if(ts.current().kind == Kind::print) continue;
    std::cout << expr(false) << '\n';
  }
}

void initialize_symbol_table() {
  table["pi"] = 3.1415926535897932385;
  table["e"] = 2.7182818284590452354;
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
