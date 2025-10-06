using static System.Console;
namespace C0307.ExtensionMethods;

internal class C0307Program
{
  static void Main()
  {
    var numbers = Enumerable.Range(1, 10);
    numbers.ForEach(WriteLine);

    string str = null;
    WriteLine(str.IsNullOrEmpty());
  }
}

public static class Tools
{
  public static void ForEach<T>(this IEnumerable<T> collection, Action<T> action)
  {
    foreach (var item in collection)
    {
      action(item);
    }
  }

  public static bool IsNullOrEmpty(this string str)
  {
    return string.IsNullOrEmpty(str);
  }
}