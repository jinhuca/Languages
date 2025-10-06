namespace C0214;

internal class C0214Program
{
  static void Main()
  {
    LoopAndLog();
  }

  private static void LoopAndLog()
  {
    foreach (var value_ in Iterator())
    {
      Console.WriteLine("Received value: {0}", value_);
    }
  }

  static IEnumerable<string> Iterator()
  {
    try
    {
      Console.WriteLine("Before first yield");
      yield return "first";
      Console.WriteLine("Between yields");
      yield return "second";
      Console.WriteLine("After second yield");
    }
    finally
    {
      Console.WriteLine("In finally block");
    }
  }
}
