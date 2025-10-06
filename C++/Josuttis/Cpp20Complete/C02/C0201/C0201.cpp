// C0201.cpp 
import std;

auto printColl = [](const auto& coll) {   // generic lambda
  for(const auto& elem : coll) {
    std::cout << elem << '\n';
  }
};

auto do_nothing = [](const auto&) {}; // generic lambda that does nothing

void printColl2(const auto& coll) {
  for(const auto& elem: coll) {
    std::cout << elem << '\n';
  }
}

template<typename T>
void printColl3(const T& coll) {   // equivalent generic function to printColl2
  for(const auto& elem: coll) {
    std::cout << elem << '\n';
  }
}

void print(auto value) { // generic function
  std::cout << value << '\n';
}

class myClass {};

void g() {
  std::vector coll {1, 2, 4, 5};
  std::string str {"Hello, world!"};
  std::vector<std::string> strColl {"Hello", "world", "from", "C++20"};

  myClass myObj;
  do_nothing(myObj); // compiles the lambda for any type
  //print(myObj);      // compilation error: no definition of operator<< for myClass
  //printColl(myObj); // compilation error: no definition of iterators in myClass

  printColl(coll);    // compiles the lambda for std::vector<int>
  printColl(strColl);     // compiles the lambda for std::string

  printColl2(coll);    // compiles the function for vector<int>
  printColl2(strColl); // compiles the function for vector<string>

  printColl3(coll);    // compiles the function template for vector<int>
  printColl3(strColl); // compiles the function template for vector<string>
}

int main() {
  g();
}
