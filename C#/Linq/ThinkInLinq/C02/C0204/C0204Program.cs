using static System.Console;

namespace C0204;

file class C0204Program
{
  public static void Main()
  {
    //DemoPercentile();
    DemoRank();
  }

  public static void DemoPercentile()
  {
    int[] nums_ = { 20, 15, 31, 34, 35, 40, 50, 90, 99, 100 };
    var xyz = nums_
      .ToLookup(k => k, k => nums_.Where(n => n < k))
      .Select(k => new KeyValuePair<int, double>
        (k.Key, 100 * ((double)k.First().Count() / (double)nums_.Length)));
    foreach(var x in xyz)
    {
      Write($"Key = {x.Key}\t");
      Write($"Value = {x.Value}");
      WriteLine();
    }
  }

  public static void DemoRank()
  {
    int[] nums_ = { 20, 15, 31, 34, 35, 40, 50, 90, 99, 100 };
    var marks = nums_
      .ToLookup(k => k, k => nums_.Where(n => n < k))
      .Select(k => new
      {
        Marks = k.Key,
        Ranks = 10 * ((double)k.First().Count() / (double)nums_.Length)
      });
        
    foreach(var x in marks)
    {
      Write($"Key = {x.Marks}\t");
      Write($"Value = {x.Ranks}");
      WriteLine();
    }
  }
}