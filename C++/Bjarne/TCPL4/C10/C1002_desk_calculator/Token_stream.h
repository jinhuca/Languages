#pragma once
#include <iostream>
#include "Token.h"
#include "Utilities.h"

class Token_stream {
public:
  Token_stream(std::istream& s) : ip { &s }, owns { false } {}
  Token_stream(std::istream* p) : ip { p }, owns { true } {}

  ~Token_stream() { close(); }

  Token get();          // get the next token from the input
  Token& current();     // get the current token

  void set_input(std::istream& s) { close(); ip = &s; owns = false; }
  void set_input(std::istream* p) { close(); ip = p; owns = true; }
private:
  void close() { if(owns) delete ip; }
  std::istream* ip;
  bool owns;
  Token ct { Kind::end };
};

Token& Token_stream::current() {
  return ct;
}

Token Token_stream::get() {
  char ch;
  do {
    if(!ip->get(ch)) {
      return ct = { Kind::end };
    }
  } while(ch != '\n' && std::isspace(ch));

  switch(ch) {
  case ';':
  case '\n':
    return ct = { Kind::print };
  case '*':
  case '/':
  case '+':
  case '-':
  case '(':
  case ')':
  case '=':
    return ct = { static_cast<Kind>(ch) };
  case '0':
  case '1':
  case '2':
  case '3':
  case '4':
  case '5':
  case '6':
  case '7':
  case '8':
  case '9':
  case '.':
  {
    ip->putback(ch);
    *ip >> ct.number_value;
    ct.kind = Kind::number;
    return ct;
  }
  default:
    if(std::isalpha(ch)) {
      ct.string_value = ch;
      while(ip->get(ch) && std::isalnum(ch)) {
        ct.string_value += ch;
      }
      ip->putback(ch);
      return ct = { Kind::name,ct.string_value };
    }
    error("bad token");
    return ct = { Kind::print };
  }
}

// Token_stream ts is an instance of the Token_stream class initialized to 
// read input from the standard input stream(std::cin)
Token_stream ts(std::cin);