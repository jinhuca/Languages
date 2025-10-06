// P019.cpp : aggregate initialization
import std;

struct Point2D {
  int x;
  int y;
};

class Point3D {
public:
  int x;
  int y;
  int z;
};

int main()
{
  Point2D point2D { 1, 2 };
  Point3D point3D { 1, 2, 3 };

  std::cout << "point2D: " << point2D.x << " " << point2D.y << '\n';
  std::cout << "point3D: " << point3D.x << " " << point3D.y << " " << point3D.z << '\n';

  Point2D p2D { .x = 1, .y = 2 };
  Point3D p3D { .x = 1, .y = 2, .z = 3 };

  std::cout << "p2D: " << p2D.x << " " << p2D.y << '\n';
  std::cout << "p3D: " << p3D.x << " " << p3D.y << " " << p3D.z << '\n';
}
