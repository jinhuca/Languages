// C120204_unspecified_number_of_arguments.cpp 
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <initializer_list>
#include "error.h"

extern void error(int severity ...);
extern void error(int severity, std::initializer_list<std::string> err);

//extern char* itoa(int, char[]);     // int to alpha

void check_args_1(int argc, char* argv[]) {
  switch(argc) {
    case 0:
      error(0, 0, nullptr);
      break;
    case 1:
      error(0, argv[0], nullptr);
      break;
    case 2:
      error(0, argv[0], argv[1], nullptr);
      break;
    default:
      char buffer[8];
      error(1, argv[0], "with", std::to_string(argc - 1), buffer, "arguments", nullptr);
  }
  std::cerr << '\n';
}

void check_args_2(int argc, char* argv[]) {
  switch(argc) {
    case 1:
      error(0, {argv[0]});
      break;
    case 2:
      error(0, {argv[0], argv[1]});
      break;
    default:
      error(1, {argv[0], "with ", std::to_string(argc - 1), " arguments"});
  }
  std::cerr << '\n';
}

void check_args_3(int argc, char* argv[]) {
  auto args = arguments(argc, argv);
  error(args.size() < 2 ? 0 : 1, args);
}

int main(int argc, char* argv[]) {
  check_args_1(argc, argv);
  check_args_2(argc, argv);
  check_args_3(argc, argv);
  // ...
}
