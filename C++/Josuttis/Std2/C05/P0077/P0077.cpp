// P0077.cpp shared_ptr
import std;

int main()
{
  // two shared pointers representing two persons by their names
  std::shared_ptr<std::string> pNico(new std::string("nico"));
  std::shared_ptr<std::string> pJutta(new std::string("jutta"));

  std::cout << *pNico << std::endl;
  std::cout << *pJutta << std::endl;

  // capitalize person names
  (*pNico)[0] = 'N';
  pJutta->replace(0, 1, "J");

  std::cout << *pNico << std::endl;
  std::cout << *pJutta << std::endl;

  // put them multiple times in a container
  std::vector<std::shared_ptr<std::string>> whoMakeCoffee;
  whoMakeCoffee.push_back(pJutta);
  whoMakeCoffee.push_back(pJutta);
  whoMakeCoffee.push_back(pNico);
  whoMakeCoffee.push_back(pJutta);
  whoMakeCoffee.push_back(pNico);

  for (auto& ptr : whoMakeCoffee) {
    std::cout << *ptr << " ";
  }
  std::cout << std::endl;

  // overwrite a name again - modify
  *pNico = "Nicolai";

  for (auto& ptr : whoMakeCoffee) {
    std::cout << *ptr << " ";
  }
  std::cout << std::endl;

  std::cout << "use_count: " << pJutta.use_count() << std::endl;
  whoMakeCoffee.clear();
  std::cout << "use_count: " << pJutta.use_count() << std::endl;
}
