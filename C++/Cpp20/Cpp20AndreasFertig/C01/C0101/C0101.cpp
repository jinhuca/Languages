// C0101.cpp :
import std;

template<typename T, typename... Ts>
constexpr inline bool are_same_v =
std::conjunction_v<std::is_same<T, Ts>...>;

template<typename T, typename...>
struct first_arg {
  using type = T;
};

template<typename... Args>
using first_arg_t = typename first_arg<Args...>::type;

template<typename... Args>
std::enable_if_t<are_same_v<Args...>, first_arg_t<Args...>>
Add(const Args&... args) noexcept
{
  return (... + args);
}

#ifdef WILL_NOT_COMPILE
void WillNotCompile()
{
  printf("%d\n", Add(2, 3, 4.0));
}
#endif

int main()
{
  std::cout << Add(2.4, 3.45, 4.2) << '\n';
  std::cout << Add(2) << '\n';
}