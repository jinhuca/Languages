using static System.Console;

namespace C0312.DeferredExtensions;

internal class C0312Program
{
  static void Main()
  {
    var numbers = new[] { 1, 2, 3, 4, 5, 6 };
    var evenNumbers = numbers.WhereWithLog(x => x % 2 == 0);
    WriteLine("Before foreach");
    foreach (var number in evenNumbers)
    {
      WriteLine($"even number: {number}");
    }
  }
}

public static class EnumerableDeferredExtensions
{
  public static IEnumerable<T> WhereWithLog<T>(this IEnumerable<T> source, Func<T, bool> predicate)
  {
    foreach (var item in source)
    {
      WriteLine($"Checking item {item}");
      if (predicate(item))
      {
        yield return item;
      }
    }
  }
}