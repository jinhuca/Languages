using static System.Console;

namespace C0303.LambdaExpressions;

public delegate bool ComparisonTest(string first, string second);
internal class C0303Program
{
  static void Main()
  {
    ComparisonTest x = (s1, s2) => s1 == s2;
    ComparisonTest y = delegate(string s1, string s2) { return s1 == s2; };

    var xy = () =>
    {
      WriteLine("Hello");
      WriteLine("Lambdas");
      return x("Hello", "Lambdas");
    };

    WriteLine(xy());
  }
}