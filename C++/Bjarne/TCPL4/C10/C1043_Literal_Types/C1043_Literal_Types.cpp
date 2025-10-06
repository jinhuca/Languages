// C1043_Literal_Types.cpp 
import std;

struct Point {
  int x, y, z;
  constexpr Point up(int d) const { return { x,y,z + d }; }
  constexpr Point move(int dx, int dy) const { return { x + dx, y + dy }; }
};

constexpr Point origo { 0,0 };
constexpr int z = origo.x;
constexpr Point a[] = {
  origo, Point{1,1}, Point{2,2}
};
constexpr int x = a[1].x;
//constexpr Point xy { 0,std::sqrt(2) };    // error: std::sqrt is not a constexpr function

constexpr int isqrt_helper(int sq, int d, int a) {
  return sq <= a ? isqrt_helper(sq + d, d + 2, a) : d;
}

constexpr int isqrt(int x) {
  return isqrt_helper(1, 3, x) / 2 - 1;
}
constexpr int square(int x) { return x * x; }
constexpr int radial_distance(Point p) {
  return isqrt(square(p.x) + square(p.y) + square(p.z));
}

constexpr Point p { 10,20,30 };   // the default constructor is constexpr
constexpr Point p2 { p.up(20)};

int main() {
  std::cout << radial_distance(p);
}
