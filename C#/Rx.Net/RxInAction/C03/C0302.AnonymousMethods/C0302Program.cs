using static System.Console;

namespace C0302.AnonymousMethods;

public delegate bool ComparisonTest(string first, string second);

public class C0302Program
{
  public static void Main(string[] args)
  {
    AnonymousTest();
    CapturedVariables();
    CapturedVariables2();
  }

  public static void AnonymousTest()
  {
    ComparisonTest lengthComparer = delegate (string first, string second)
    {
      return first.Length == second.Length;
    };

    WriteLine($"anonymous method returned: {lengthComparer("Hello", "World")}");
  }

  static bool AreSimilar(string[] leftItems, string[] rightItems, ComparisonTest tester)
  {
    if (leftItems.Length != rightItems.Length)
      return false;

    for (int i = 0; i < leftItems.Length; i++)
    {
      if (tester(leftItems[i], rightItems[i]) == false)
      {
        return false;
      }
    }
    return true;
  }

  private static void CapturedVariables()
  {
    ComparisonTest comparer;
    {
      int moduloBase = 2;
      comparer = delegate (string s1, string s2)
      {
        WriteLine($"the modulo base is: {moduloBase}");
        return ((s1.Length % moduloBase) == (s2.Length % moduloBase));
      };
      moduloBase = 3;
    }
    var similarByMod = AreSimilar(new[] { "AB" }, new[] { "ABCD" }, comparer);

    WriteLine($"Similar by modulo: {similarByMod}");
  }

  public delegate void ActionDelegate();

  private static void CapturedVariables2()
  {
    var actions = new List<ActionDelegate>();
    for (var i = 0; i < 5; i++)
    {
      actions.Add(delegate { WriteLine(i); });
    }

    foreach (var act in actions) act();
  }
}