// Reference Type

int x = 1;
int y = x;
x = 2;
Console.WriteLine(x);
Console.WriteLine(y);

Point p1 = new Point { X = 1, Y = 2 };
Point p2 = p1;
p1.X = 3;

Console.WriteLine(p1.X);
Console.WriteLine(p2.X);

internal class Point
{
  public int X, Y;
}
