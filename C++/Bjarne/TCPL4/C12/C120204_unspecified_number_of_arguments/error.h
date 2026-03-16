#pragma once
#include <cstdarg>
#include <iostream>

void error(int severity ...) {   // "severity" followed by a zero-terminated list of char's
  va_list ap;
  va_start(ap, severity);       // arg startup

  for(;;) {
    char* p = va_arg(ap, char*);
    if(p == nullptr) break;
    std::cerr << p << ' ';
  }

  va_end(ap);                   // arg cleanup

  std::cerr << '\n';
  if(severity) exit(severity);
}

void error(int severity, std::initializer_list<std::string> err) {
  for(auto& s : err)
    std::cerr << s << ' ';
  std::cerr << '\n';
  if(severity) exit(severity);
}