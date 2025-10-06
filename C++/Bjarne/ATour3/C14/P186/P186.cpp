// P186.cpp
import std;

template<std::ranges::forward_range R>
requires std::sortable<std::ranges::iterator_t<R>>
void my_sort(R& r)
{
  return my_sort(r.begin(), r.end());
}

void user(std::ranges::forward_range auto& r)
{
  std::ranges::filter_view v { r,[](int x) { return x % 2; } };    // view (only) odd numbers from r
  std::cout << "odd number: ";
  for(int x : v)
    std::cout << x << ' ';
}

int main()
{
  std::cout << "Hello World!\n";
}
