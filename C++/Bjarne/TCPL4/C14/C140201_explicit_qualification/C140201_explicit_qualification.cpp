// C140201_explicit_qualification.cpp
#include <iostream>

namespace Parser {
double expr(bool); // declaration
double term(bool);
double prim(bool);
}

double val = Parser::expr(true);  // use

double Parser::expr(bool b) {    // definition
  // ...
    return 1.1;
}

void Parser::logical(bool);     // error: no logical(boo) in Parser
double Parser::trem(bool);      // error: no trem() in Parser (misspelling)
double Parser::prim(int);       // error: Parser::prim() takes a bool argument (wrong type)

int f();    // global function
int g() {
    int f;     // local variable; hide the global function
    f();       // error: we can't call an int
    ::f();     // ok: call the global function
}

int main() {
    
}
