// C1401Introduction.cpp : 
import std;

template<std::ranges::forward_range R>
requires std::sortable<std::ranges::iterator_t<R>>
void my_sort(R& r)
{
  return my_sort(r.begin(), r.end());
}

int main()
{
    std::cout << "Hello World!\n";
}
