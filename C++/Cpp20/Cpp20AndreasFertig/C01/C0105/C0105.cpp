// C0105.cpp : Concept demo.
import std;

template<typename T, typename... Ts>
constexpr bool are_same_v =
std::conjunction_v<std::is_same<T, Ts>...>;

template<typename... Args>
  requires are_same_v<Args...>
auto Add(Args&&... args) noexcept
{
  return (... + args);
}

int main()
{
  std::cout << Add(2.4, 1.3, 7.4) << '\n';
  std::cout << Add(1, 2, 3, 4, 5) << '\n';
  std::cout << Add(2.1, 3.2, 0.2) << '\n';
}
