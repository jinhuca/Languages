// P089.cpp

import std;

int area(int length, int width)
// calculate area of a rectangle
{
  return length * width;
}

int framed_area(int x, int y)
// calculate area within frame
{
  return area(x - 2, y - 2);
}

void test(int x, int y, int z)
{
  int area1 = area(x, y);
  int area2 = framed_area(1, z);
  int area3 = framed_area(y, z);
  double ratio = double(area1) / area3;     // convert to double to get floating-point division
}

int main()
{
  int x = -1, y = 2, z =3;
  if (x <= 0)
    throw std::runtime_error("non-positive x");
  if (y <= 0)
    throw std::runtime_error("non-positive y");

  test(x, y, z);
}
