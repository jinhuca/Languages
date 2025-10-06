// C030101_nullptr.cpp: nullptr and std::nullptr
import std;

void f(int x)
{
    std::cout << "calls void f(int)\n";
}

void f(void* p)
{
    std::cout << "calls void f(void*)\n";
}

void g()
{
    f(0);
    f(nullptr);
    f(1);
}

int main()
{
    g();
}
