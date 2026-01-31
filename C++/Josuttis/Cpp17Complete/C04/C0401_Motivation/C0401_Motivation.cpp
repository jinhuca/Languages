// C0401_Motivation.cpp 
#include <iostream>

struct Data {
  std::string name;
  double value;
};

struct Cpp14Data :Data {
  bool done;
  Cpp14Data(const std::string& s, double d, bool b) :
    Data{ s,d }, done{ b } {
  }
};

int main() {
  Cpp14Data y{ "test1", 6.78, false };
}
