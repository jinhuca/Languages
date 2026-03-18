// C130300_resources_management.cpp 
#pragma warning(disable : 4996)
#include <iostream>
#include <cstdio>
#include <exception>
#include <string>

using std::string;

void naively_use_file(const char* fn) {
  FILE* f = fopen(fn, "r");
  // ... use f ...
  fclose(f);
}

void clumsily_use_file(const char* fn) {
  FILE* f = fopen(fn, "r");
  try {
    // ... use f ...
  }
  catch(...) {  // catch every possible exception
    fclose(f);
    throw;
  }
  fclose(f);
}

class File_ptr {    // RAII
  FILE* p;
public:
  File_ptr(const char* n, const char* a) : p{fopen(n,a)} {
    if(p == nullptr) throw std::runtime_error{"File_ptr: can't open file"};
  }

  File_ptr(const string& n, const char* a) : File_ptr{n.c_str(), a} {
  }

  explicit File_ptr(FILE* pp) :p{pp} {    // assume ownership of pp
    if(p == nullptr) throw std::runtime_error("File_ptr: nullptr");
  }

  // ... suitable move and copy operations ...
  ~File_ptr() { fclose(p); }

  operator FILE* () { return p; }
};

void use_file_in_raii_way(const char* fn) {
  File_ptr f(fn, "r");
  // ... use f ...
}

int main() {

}
