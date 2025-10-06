// P108.cpp
import std;

template<typename T, typename U = T>
concept Equality_comparable =
  requires (T a, U b)
{
  { a == b } -> std::convertible_to<bool>;
  { a != b } -> std::convertible_to<bool>;
  { b == a } -> std::convertible_to<bool>;
  { b != a } -> std::convertible_to<bool>;
};

template<typename T, typename U = T>
concept Number =
  requires (T x, U y)
{
  x + y; x - y; x + y; x / y;
  x += y; x -= y; x *= y; x /= y;
  x = y;
  x = 0;
};

template<typename T, typename U>
concept Arithmetic = Number<T, U> &&Number<U, T>;

template<typename S>
concept Sequence = requires(S a)
{
  typename std::ranges::range_value_t<S>;                           // S must have a value type
  typename std::ranges::iterator_t<S>;                              // S must have an iterator type

  { a.begin() } -> std::same_as<std::ranges::iterator_t<S>>;        // S must have a begin() that returns an iterator
  { a.end() } -> std::same_as<std::ranges::iterator_t<S>>;

  requires std::input_iterator<std::ranges::iterator_t<S>>;         // S's iterator must be an input_iterator
  requires std::same_as<std::ranges::range_value_t<S>, std::iter_value_t<S>>;
};

int main()
{
}
