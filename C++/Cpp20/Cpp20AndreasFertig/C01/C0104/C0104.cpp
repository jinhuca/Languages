// C0104.cpp
import std;

template<typename... Args>
#include <type_traits>

// are_same: true if 0 or 1 types or all types are the same
template<typename...> struct are_same : std::true_type {};

template<typename T, typename U, typename... Rest>
struct are_same<T, U, Rest...>
    : std::conditional_t<std::is_same<T, U>::value, are_same<T, Rest...>, std::false_type>
{};

// If your compiler supports variable templates (C++14+), you can also add:
#if __cplusplus >= 201402L
template<typename... Args>
inline constexpr bool are_same_v = are_same<Args...>::value;
#endif

// first_arg_t: alias for the first type in a pack
template<typename First, typename...> using first_arg_t = First;
Add(const Args&... args) noexcept {
  return (... + args);
}

int main() {}
