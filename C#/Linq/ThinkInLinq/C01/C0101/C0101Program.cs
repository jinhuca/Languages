using static System.Console;

namespace C0101;

internal class C0101Program
{
  static void Main()
  {
    FirstOrderFunctionDemo();
    HighOrderFunctionDemo();
  }

  private static void FirstOrderFunctionDemo()
  {
    Func<int, int> f = x => x + 1;
    Func<int, int> g = x => x + 2;

    WriteLine(f(3));
    WriteLine(g(3));
  }

  private static void HighOrderFunctionDemo()
  {
    Func<Func<int, int>, Func<int, int>, int, int> fog = (f1, g1, x) => f1(g1(x));
    var result_ = fog(x => x + 21, x => x * 2, 12);
    WriteLine(result_);
  }
}