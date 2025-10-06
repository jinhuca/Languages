using static System.Console;

namespace C0311.YieldReturn;

internal class C0311Program
{
  static void Main()
  {
    //UnderstandYield();
    GetFibonacciDemo();
  }

  static IEnumerable<string> GetGreetings()
  {
    yield return "Hello";
    yield return "Hi";
  }

  static void UnderstandYield()
  {
    foreach (var greeting in GetGreetings())
    {
      WriteLine(greeting);
    }
  }

  static void GetFibonacciDemo()
  {
    foreach (var item in GenerateFibonacci().Take(10))
    {
      WriteLine(item);
    }
  }

  static IEnumerable<int> GenerateFibonacci()
  {
    int a = 0;
    int b = 1;
    yield return a;
    yield return b;
    while (true)
    {
      b = a + b;
      a = b - a;
      yield return b;
    }
  }
}