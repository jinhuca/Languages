#include <istream>
#include <vector>

import Shape;
import Circle;
import Smiley;
import Triangle;
import Point;

enum class Kind { circle, triangle, smiley };

void rotate_all(std::vector<Shape*>& v, int angle)
{
  for (auto p : v)
    p->rotate(angle);
}

int main()
{
  
}
