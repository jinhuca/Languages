// C130601_a_simple_vector.cpp
#include "vector.h"
#include <iostream>

void f()
{
    simple_vector::vector<int> v(3);
    std::cout << v.size() << '\n';
}

int main()
{
    f();
}