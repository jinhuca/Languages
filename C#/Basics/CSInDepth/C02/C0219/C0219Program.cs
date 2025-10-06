namespace C0219;

internal class C0219Program
{
  static void Main()
  {
    foreach (var value_ in GenerateIntegers(5))
    {
      Console.WriteLine(value_);
    }
  }

  static IEnumerable<int> GenerateIntegers(int count)
  {
    try
    {
      for (int i = 0; i < count; i++)
      {
        Console.WriteLine("Yielding {0}", i);
        yield return i;
        int doubled = i * 2;
        Console.WriteLine("Yielding {0}", doubled);
        yield return doubled;
      }
    }
    finally
    {
      Console.WriteLine("In finally block!");
    }
  }
}