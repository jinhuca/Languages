namespace C1101;

internal class C1101Program
{
  static void Main(string[] args)
  {
    var source_ = new List<int> { 3, 1, 5, 6, 7, 84, -21};
    var result_ = GetMinMax(source_);
    Console.WriteLine(result_);
  }

  static (int min, int max) GetMinMax(IEnumerable<int> source)
  {
    using var iterator_ = source.GetEnumerator();
    if(!iterator_.MoveNext())
    {
      throw new InvalidOperationException("Cannot find min/max of an empty sequence.");
    }
    int min_ = iterator_.Current;
    int max_ = iterator_.Current;
    while(iterator_.MoveNext())
    {
      min_ = Math.Min(min_, iterator_.Current);
      max_ = Math.Max(max_, iterator_.Current);
    }
    return (min_, max_);
  }
}
