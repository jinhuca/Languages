// C050201_shared_ptr.cpp 
#include <iostream>
#include <string>
#include <vector>
#include <memory>

int main() {
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
}
