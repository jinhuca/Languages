namespace C0202;

file class C0202Program
{
  static void Main()
  {
    PythagoreanTriples(10);
  }

  private static void PythagoreanTriples(int upper)
  {
    var result = Enumerable.Range(2, upper)
      .Select(c => new { 
        Length = 2 * c, 
        Height = c * c - 1, 
        Hypotenuse = c * c + 1 });

    foreach (var item in result)
    {
      WriteLine(item.Length + "\t" + item.Height + "\t" + item.Hypotenuse);
    }
  }
}