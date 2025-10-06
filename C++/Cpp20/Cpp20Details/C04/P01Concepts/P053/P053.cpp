// P053.cpp: requiresClause.cpp - using a compile-time predicate in a requires clause
import std;

template<unsigned int i>
  requires(i <= 20)
int sum(int j) {
  return i + j;
}

int main()
{
  std::cout << "sum<20>(2000): " << sum<20>(2000) << '\n';
  //std::cout << "sum<23>(2000): " << sum<23>(2000) << '\n';    // ERROR
}
