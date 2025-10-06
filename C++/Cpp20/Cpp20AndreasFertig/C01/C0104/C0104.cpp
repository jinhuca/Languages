// C0104.cpp
import std;

template<typename... Args>
std::enable_if_t<are_same_v<Args...>, first_arg_t<Args...>>


int main()
{
}
