// C080204_structures_and_arrays.cpp
#include <iostream>

struct Point {
  int x, y;
};

void array_of_structs() {
  Point points[3] { {1, 2}, {3, 4}, {5, 6} };    // array of 3 Points
  int x2 = points[2].x;                          // access member of struct in array
}

struct Array {
  Point elem[3];    // array of 3 Points
};

Array shift(Array a, Point p) {
  for(int i = 0; i != 3; ++i) {
    a.elem[i].x += p.x;
    a.elem[i].y += p.y;
  }
  return a;
}

void struct_contains_array() {
  Array points { { {1, 2}, {3, 4}, {5, 6} } };  // Array contains an array of 3 Points
  int y2 = points.elem[2].y;                    // access member of struct in array contained in struct
  Array ax = shift(points, { 10, 20 });         // pass struct containing array to function
};

template<typename T, size_t N>
struct array{
  T elem[N];
  
  T* begin() { return &elem[0]; }
  const T* begin() const noexcept { return &elem[0]; }
  T* end() { return &elem[0] + N; }
  const T* end() const noexcept { return &elem[0] + N; }

  constexpr size_t size() const noexcept { return N; }

  T& operator[](size_t i) { return elem[i]; }
  const T& operator[](size_t i) const { return elem[i]; }

  T* data() { return &elem[0]; }
  const T* data() const noexcept { return &elem[0]; }
};

using Point_array = array<Point, 3>;  // array of 3 Points

Point_array shift(Point_array a, Point p) {
  for(int i = 0; i != a.size(); ++i) {
    a[i].x += p.x;
    a[i].y += p.y;
  }
  return a;
}

void struct_contains_array_with_template() {
  Point_array points { { {1, 2}, {3, 4}, {5, 6} } };  // Point_array contains an array of 3 Points
  int x2 = points[2].x;                          // access member of struct in array contained in struct
  int y2 = points[2].y;                          // access member of struct in array contained in struct

  Point_array ax = shift(points, { 10, 20 });         // pass struct containing array to function
}

int main() {
  array_of_structs();
  struct_contains_array();
  struct_contains_array_with_template();
}
