namespace C0102.ShoppyExample.Domain;

internal class Position
{
  public double X { get; set; }
  public double Y { get; set; }

  public static double Distance(Position left, Position right)
  {
    var diff = new Position
    {
      X = left.X - right.X,
      Y = left.Y = right.Y
    };
    return Math.Round(DotProduct(diff, diff), 0);
  }

  public static double DotProduct(Position left, Position right)
  {
    return Math.Round(Math.Sqrt(left.X * right.X + left.Y * right.Y), 0);
  }
}