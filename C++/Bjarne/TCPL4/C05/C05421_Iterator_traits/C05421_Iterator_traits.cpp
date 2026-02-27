// C05421_Iterator_traits.cpp 
import std;

template<typename Ran>
void sort_helper(Ran beg, Ran end, std::random_access_iterator_tag) {
  sort(beg, end);
}

template<typename C>
using Value_type = typename C::value_type;

template<typename For>
void sort_helper(For beg, For end, std::forward_iterator_tag) {
  std::vector<Value_type<For>> v { beg, end };
  sort(v.begin(), v.end());
  copy(v.begin(), v.end(), beg);
}

template<typename C>
void sort(C& c) {
  using Iter = Iterator_type<C>;
  sort_helper(c.begin(), c.end(), typename std::iterator_traits<Iter>::iterator_category {});
}

int main() {
  std::cout << "Hello World!\n";
}
