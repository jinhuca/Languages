// C060202_Associative_containers.cpp 
import std;

void multiset_example() {
  std::multiset<std::string> cities{
    "Braunschweig", "Hanover", "Frankfurt", "New York",
    "Chicago", "Toronto", "Paris", "Frankfurt"
  };
  for (const auto& elem : cities) {
    std::cout << elem << ' ';
  }
  std::cout << '\n';

  cities.insert({ "London", "Munich", "Hanover", "Braunschweig"});
  for (const auto& elem : cities) {
    std::cout << elem << ' ';
  }
  std::cout << '\n';
}

void multimap_example() {
  std::multimap<int, std::string> coll {
    { 5, "tagged" }, 
    { 2, "a" }, 
    { 1, "this" },
    { 4, "of" }, 
    { 6, "strings" }, 
    { 1, "is" },
    { 3, "multimap" }
  };
  for (const auto& elem : coll) {
    std::cout << elem.second << ' ';
  }
}

void unordered_multiset_example() {
  std::unordered_multiset<std::string> cities{
    "Braunschweig", "Hanover", "Frankfurt", "New York",
    "Chicago", "Toronto", "Paris", "Frankfurt"
  };
  for (const auto& elem : cities) {
    std::cout << elem << ' ';
  }
  std::cout << '\n';
  cities.insert({ "London", "Munich", "Hanover", "Braunschweig" });
  for (const auto& elem : cities) {
    std::cout << elem << ' ';
  }
  std::cout << '\n';
}

int main() {
  //multiset_example();
  //multimap_example();
  unordered_multiset_example();
}
