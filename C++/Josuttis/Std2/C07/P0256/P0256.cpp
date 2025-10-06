// P0256.cpp : 
import std;

// container has constructor for an initializer list
void f() {
  // initialize a vector with some specific values
  const std::vector<int> v1 = { 1, 2, 3, 5, 7, 11, 13, 17, 21 };
  // same with different syntax
  const std::vector<int> v2 { 1, 2, 3, 5, 7, 11, 13, 17, 21 };
  // initialize an unordered set with "hello" and two empty strings
  std::unordered_set<std::string> w = { "hello", std::string(), "" };

  for (const auto& e : w) {
    std::cout << e << std::endl;
  }
}

// container has constructor for a given range
void g() {
  std::list<int> l { 1, 2, 3 };

  // copy all elements of the list as floats into a vector
  std::vector<float> c(l.begin(), l.end());

  for (const auto& e : c) {
    std::cout << e << std::endl;
  }

  // move all elements of the list into a vector
  std::vector<float> cc(std::make_move_iterator(l.begin()), std::make_move_iterator(l.end()));

  for (const auto& e : cc) {
    std::cout << e << std::endl;
  }

  for (const auto& e : l) {
    std::cout << e << std::endl;
  }
}

void h() {
  int carray [] { 32, 23, 17, 13, 15, 19 };
  std::set<int> c(std::begin(carray), std::end(carray));
  for (const auto& e : c) {
    std::cout << e << std::endl;
  }
}

int main()
{
  h();
}
