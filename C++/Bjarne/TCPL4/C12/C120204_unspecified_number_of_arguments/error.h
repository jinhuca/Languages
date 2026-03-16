#pragma once
#include <cstdarg>
#include <iostream>
#include <vector>
#include <string>

using std::string;
using std::vector;
using std::cerr;

void error(int severity ...) {   // "severity" followed by a zero-terminated list of char's
  va_list ap;
  va_start(ap, severity);       // arg startup

  for(;;) {
    char* p = va_arg(ap, char*);
    if(p == nullptr) break;
    cerr << p << ' ';
  }

  va_end(ap);                   // arg cleanup

  cerr << '\n';
  if(severity) exit(severity);
}

void error(int severity, std::initializer_list<std::string> err) {
  for(auto& s : err)
    cerr << s << ' ';
  cerr << '\n';
  if(severity) exit(severity);
}

void error(int severity, const vector<string>& err) {
  for(auto& s : err)
    cerr << s << ' ';
  cerr << '\n';
  if(severity) exit(severity);
}

vector<string> arguments(int argc, char* argv[]) {  // package arguments
  vector<string> res;
  for(int i = 0; i != argc; ++i)
    res.push_back(argv[i]);
  return res;
}
