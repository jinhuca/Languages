#include "Parser.h"
#include "Error.h"
#include "Lexer.h"
#include "Table.h"
#include "Driver.h"

using namespace Error;
using namespace Lexer;
using namespace Table;

double Parser::prim(bool get) {
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

double Parser::term(bool get) {
  return 0;
}

double Parser::expr(bool get) {
  return 0;
}