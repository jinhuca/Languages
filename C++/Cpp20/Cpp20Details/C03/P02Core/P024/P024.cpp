// P024.cpp : template parameters for lambdas
import std;

int main()
{
  auto foo = []<typename T>(std::vector<T> const& vec) {
    for (auto& const e : vec) { std::cout << e << '\n'; }
  };

}
