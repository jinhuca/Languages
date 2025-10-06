// P055.cpp : compile-time predicates
import std;

struct Test {};

int main()
{
  std::cout << std::boolalpha;
  std::cout << "std::three_way_comparable<int>: "
    << std::three_way_comparable<int> << '\n';

  std::cout << "std::three_way_comparable<double>: ";
  if (std::three_way_comparable<double>)
    std::cout << "True.\n";
  else 
    std::cout << "False.\n";

  static_assert(std::three_way_comparable<std::string>);

  std::cout << "std::three_way_comparable<Test>: ";
  if constexpr (std::three_way_comparable<Test>)
    std::cout << "True";
  else
    std::cout << "False";
}
