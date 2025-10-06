using static System.Console;
namespace C0304.ActionFunc;

internal class C0304Program
{
  static void Main(string[] args)
  {
    var oddNumbers = new[] { 1, 3, 5, 7, 9 };

    //ForEachInt(oddNumbers, x => WriteLine(x * 2));

    //ForEachInt(oddNumbers, WriteLine);

    var numbers = Enumerable.Range(1, 10);
    ForEach(numbers, WriteLine, n => n % 2 == 0);
  }

  static void ForEachInt(IEnumerable<int> collection, Action<int> action)
  {
    foreach (var item in collection)
    {
      action(item);
    }
  }

  static void ForEach<T>(IEnumerable<T> collection, Action<T> action)
  {
    foreach (var item in collection)
    {
      action(item);
    }
  }

  static void ForEach<T>(IEnumerable<T> collection, Action<T> action, Func<T, bool> predicate)
  {
    foreach (var item in collection)
    {
      if (predicate(item)) action(item);
    }
  }
}