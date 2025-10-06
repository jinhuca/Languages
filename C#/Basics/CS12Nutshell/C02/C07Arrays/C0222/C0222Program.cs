using static System.Console;

// Default Element Initialization - Value Types
{
  Point[] a = new Point[1000];
  int x = a[500].X; // 0
  WriteLine(x);
}

public struct Point { public int X, Y; }