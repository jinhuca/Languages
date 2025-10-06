// C0824_Structures_Arrays.cpp 
import std;

struct Point {
  int x, y;
};

// Points in array
Point points[3] { {1,2},{3,4},{5,6} };
int x2 = points[2].x;

struct Array {
  Point elem[3];
};

// Points in array in Array
Array points2 { {{1,2},{3,4},{5,6}} };
int y2 = points2.elem[2].y;

Array shift(Array a, Point p) {
  for(int i = 0; i != 3; ++i) {
    a.elem[i].x += p.x;
    a.elem[i].y += p.y;
  }
  return a;
}

void f() {
  Array ax = shift(points2, { 10,20 });
}



int main() {
  f();
}
