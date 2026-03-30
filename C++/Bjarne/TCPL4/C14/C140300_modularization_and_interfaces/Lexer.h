#pragma once
// lexer.h

namespace Lexer {
  enum class Kind : char {
    name, number, end, plus = '+', minus = '-', mul = '*', div = '/', print = ';'
  };
  class Token {};
  class Token_stream {};

  Token_stream ts;
}