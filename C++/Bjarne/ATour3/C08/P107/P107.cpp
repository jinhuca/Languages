// P107.cpp : Define concepts.
import std;

template<typename B>
concept Boolean = requires(B x, B y)
{
  { x = true };
  { y = true };
  { x = (x == y) };
  { x = (x != y) };
  { x = !x };
  { x = (x = y) };
};

template<typename T>
concept Hashable = requires(T a)
{
  { std::hash<T>{}(a) } -> std::convertible_to<std::size_t>;
};

template<typename T, typename U>
concept Equality_comparable = requires (T a, U b) {
  { a == b } -> Boolean;
  { a != b } -> Boolean;
  { b == a } -> Boolean;
  { b != a } -> Boolean;
};

struct S { int a; };

int main()
{
  if constexpr (Equality_comparable<int, int>)
    std::cout << "type int is equality comparable." << '\n';
  else
    std::cout << "type int is not equality comparable." << '\n';

  if constexpr (Equality_comparable<S, S>)
    std::cout << "struct S is equality comparable." << '\n';
  else
    std::cout << "struct S is not equality comparable." << '\n';
}
