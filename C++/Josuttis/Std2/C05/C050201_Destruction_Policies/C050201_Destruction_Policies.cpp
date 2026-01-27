// C050201_Destruction_Policies.cpp 
#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include <cstdio>

class FileDeleter {
private:
  std::string filename;
public:
  FileDeleter(const std::string& fn) : filename(fn) {}
  void operator()(std::ofstream* fp) {
    fp->close();
    std::remove(filename.c_str());
  }
};

int main() {
  // create and open temporary file:
  std::shared_ptr<std::ofstream> fp(new std::ofstream("tmpfile.txt"), FileDeleter("tmpfile.txt"));
}
