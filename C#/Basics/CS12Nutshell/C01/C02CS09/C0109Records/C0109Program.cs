Point p1 = new Point(2, 3);
Point p2 = p1 with { Y = 4 };
Console.WriteLine(p2);

public record Point
{
  public double X { get; init; }
  public double Y { get; init; }

  public Point(double x, double y) => (X, Y) = (x, y);
}