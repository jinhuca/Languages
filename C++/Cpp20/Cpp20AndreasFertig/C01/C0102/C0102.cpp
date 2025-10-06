// C0102.cpp : C++14 for concepts
//
#include <iostream>

template<typename T>
constexpr T pi(3.14);

template<typename T, typename U>
constexpr bool is_same_v = std::is_same<T, U>::value;


int main()
{
  std::cout << pi<int> << '\n';
  std::cout << pi<double> << '\n';
}
