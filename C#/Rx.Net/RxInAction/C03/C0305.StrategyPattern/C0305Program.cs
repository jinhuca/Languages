using static System.Console;

namespace C0305.StrategyPattern;

public class C0305Program
{
  public static void Main()
  {
    //StrategyPatternDemo();
    StrategyPatternGenericDemo();
  }

  private static void StrategyPatternDemo()
  {
    var words = new List<string> { "ab", "a", "aabb", "abc" };
    words.Sort(new LengthComparer());
    WriteLine(string.Join(", ", words));
  }

  private static void StrategyPatternGenericDemo()
  {
    var words = new List<string> { "ab", "a", "aabb", "abc" };
    words.Sort(new GenericComparer<string>((x, y) => (x.Length == y.Length) ? 0 : (x.Length > y.Length) ? 1 : -1));
    WriteLine(string.Join(", ", words));
  }
}

class LengthComparer : IComparer<string>
{
  public int Compare(string? x, string? y)
  {
    if (x?.Length == y?.Length)
    {
      return 0;
    }
    return x?.Length > y?.Length ? 1 : -1;
  }
}

class GenericComparer<T> : IComparer<T>
{
  private Func<T, T, int> CompareFunc { get; set; }

  public GenericComparer(Func<T, T, int> compareFunc)
  {
    CompareFunc = compareFunc;
  }

  public int Compare(T? x, T? y) => CompareFunc(x, y);
}