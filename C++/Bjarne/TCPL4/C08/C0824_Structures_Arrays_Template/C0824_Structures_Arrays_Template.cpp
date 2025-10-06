// C0824_Structures_Arrays_Template.cpp 
import std;

struct Point {
  int x, y;
};

template<typename T, size_t N>
struct array {
  using size_type = size_t;
  T elem[N];

  array(std::initializer_list<T> lst) {
    std::copy(lst.begin(), lst.end(), elem);
  }

  T* begin() noexcept { return elem; }
  const T* begin() const noexcept { return elem; }
  T* end() noexcept { return elem + N; }
  const T* end() const noexcept { return elem + N; }

  constexpr size_type size() noexcept { return N; }

  T& operator[](size_type n) { return elem[n]; }
  const T& operator[](size_type n) const { return elem[n]; }

  T* data() noexcept { return elem; }
  const T* data() const noexcept { return elem; }
};

using Array = array<Point, 3>;    // array of 3 Points

Array shift(Array a, Point p) {
  for(int i = 0; i != a.size(); ++i) {
    a[i].x += p.x;
    a[i].y += p.y;
  }
  return a;
}

void f() {
  Array points { {1, 2}, {3, 4}, {5, 6} };
  int x2 = points[2].x;
  int y2 = points[2].y;
  Array ax = shift(points, { 10,20 });
}

int main() {
  f();
}
