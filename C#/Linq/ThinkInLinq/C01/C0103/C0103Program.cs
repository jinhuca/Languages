using static System.Console;

namespace C0103;

internal class C0103Program
{
  private static IEnumerable<int> _ints = new[] { 1, 3, 4, 5, 6, 73, 4, 3, 90, 100 };

  static void Main(string[] args)
  {
    GeneratorOpsDemo();
    //StatisticalOpsDemo();
  }

  static void GeneratorOpsDemo()
  {
    var g1_ = Enumerable.Range(1, 10);
    foreach(var item in g1_)
    {
      WriteLine(item);
    }

    var g2_ = Enumerable.Repeat(1, 4);
    foreach(var item in g2_)
    {
      WriteLine(item);
    }

    var g3_ = Enumerable
      .Range('A', 'Z' - 'A' + 1)
      .Select(x => (char)x);
    foreach (var x in g3_)
    {
      WriteLine(x);
    }
  }

  static void StatisticalOpsDemo()
  {
    WriteLine(_ints.Count());
    WriteLine(_ints.Any());
    WriteLine(_ints.Any(x => x % 2 == 0));
    WriteLine(_ints.All(x => x % 2 == 0));
    //WriteLine(_ints.Single(x => x % 3 == 0));
    try
    {
      WriteLine(_ints.SingleOrDefault(x => x % 3 == 0));
    }
    catch (Exception ex)
    {
      WriteLine(ex.Message);
    }
  }

  static void ProjectorsDemo()
  {

  }

  static void FiltersDemo()
  {

  }
}