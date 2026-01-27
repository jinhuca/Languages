// C050201_shared_ptr.cpp 
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "C050201_shared_ptr.h"

void create_shared_ptr_example0() {
  std::shared_ptr<int> pInt1(new int(42));
  std::shared_ptr<int> pInt2{ new int(43) };
  std::shared_ptr<int> pInt3 = std::make_shared<int>(44);

  std::cout << "pInt1: " << *pInt1 << '\n';
  std::cout << "pInt1 use count: " << pInt1.use_count() << '\n';
}

void create_shared_ptr_example1() {
  // create a shared pointer to an integer
  std::shared_ptr<int> pInt(new int(42));
  // print the value and the use count
  std::cout << "Value: " << *pInt << ", use_count: " << pInt.use_count() << '\n';
  // create another shared pointer pointing to the same integer
  std::shared_ptr<int> pInt2 = pInt;
  // print the value and the use count again
  std::cout << "Value: " << *pInt2 << ", use_count: " << pInt.use_count() << '\n';
}

void create_shared_ptr_example2() {
  // two shared pointers representing two persons by their name
  std::shared_ptr<std::string> pNico(new std::string("nico"));
  std::shared_ptr<std::string> pJutta(new std::string("jutta"));

  // capitalize person names
  (*pNico)[0] = 'N';
  pJutta->replace(0, 1, "J");

  // put them multiple times in a container
  std::vector<std::shared_ptr<std::string>> whoMadeCoffee;
  whoMadeCoffee.push_back(pJutta);
  whoMadeCoffee.push_back(pJutta);
  whoMadeCoffee.push_back(pNico);
  whoMadeCoffee.push_back(pJutta);
  whoMadeCoffee.push_back(pNico);

  // print all elements
  for (auto ptr : whoMadeCoffee) {
    std::cout << *ptr << " ";
  }
  std::cout << '\n';

  // overwrite a name again
  *pNico = "Nicolai";

  // print all elements again
  for (auto ptr : whoMadeCoffee) {
    std::cout << *ptr << " ";
  }
  std::cout << '\n';

  // printsome internal data
  std::cout << "use_count: " << whoMadeCoffee[0].use_count() << '\n';
}

void reset_shared_ptr() {
  std::shared_ptr<int> p = std::make_shared<int>(42);
  p.reset();
  std::cout << "Inside reset_shared_ptr: use_count = " << p.use_count() << '\n';
  p.reset(new int(100));
  std::cout << "Inside reset_shared_ptr: use_count = " << p.use_count() << '\n';
}

void delete_shared_ptr() {
  std::shared_ptr<int> pInt(new int(42),
    [](int* p) {
      std::cout << "Deleting integer: " << *p << '\n';
      delete p; 
    });

  std::shared_ptr<int> pIntArr(new int[10],
    [](int* p) {
      std::cout << "Deleting integer array\n";
      delete[] p; 
    });
}

int main() {
  //create_shared_ptr_example0();
  //create_shared_ptr_example1();
  //create_shared_ptr_example2();
  //reset_shared_ptr();
  delete_shared_ptr();
}
