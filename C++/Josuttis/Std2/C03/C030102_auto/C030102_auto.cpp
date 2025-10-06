// C030102_auto.cpp
import std;

double g()
{
    return 1.23;
}

void f()
{
    auto i = 42;
    auto d = g();
}

auto lambda = [](int x) -> bool { return x > 0; };

int main()
{
    std::cout << std::boolalpha;
    std::cout << lambda(3) << '\n';
}
