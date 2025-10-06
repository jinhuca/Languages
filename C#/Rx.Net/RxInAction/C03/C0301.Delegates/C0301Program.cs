using static System.Console;

namespace C0301.Delegates;

public delegate bool ComparisonTest(string first, string second);

public class StringComparators
{
  public static bool CompareLength(string first, string second) => first.Length == second.Length;
  public bool CompareContent(string first, string second) => first == second;
}

public class C0301Program
{
  static void Main(string[] args)
  {
    DelegateInstance();
    TestSimilar();
  }

  private static void DelegateInstance()
  {
    string s1_ = "Hello";
    string s2_ = "World";
    var comparators_ = new StringComparators();
    ComparisonTest test_ = comparators_.CompareContent;
    WriteLine($"CompareContent returned: {test_(s1_, s2_)}");

    test_ = StringComparators.CompareLength;
    WriteLine($"CompareLength returned: {test_(s1_, s2_)}");
  }

  static bool AreSimilar(string[] leftItems, string[] rightItems, ComparisonTest tester)
  {
    if (leftItems.Length != rightItems.Length) return false;
    for (int i = 0; i < leftItems.Length; i++)
    {
      if (tester(leftItems[i], rightItems[i]) == false)
      {
        return false;
      }
    }
    return true;
  }

  static void TestSimilar()
  {
    string[] cities = { "London", "Madrid", "TelAviv" };
    string[] friends = { "Minnie", "Goofey", "MickeyM" };
    WriteLine($"Are friends and cities similar? {AreSimilar(friends, cities, StringComparators.CompareLength)}");
  }
}