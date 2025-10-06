namespace C0216;

internal class C0216Program
{
  static void Main(string[] args)
  {
    BreakOutLoop();
  }

  private static void BreakOutLoop()
  {
    foreach (var value_ in Iterator())
    {
      Console.WriteLine("Received value: {0}", value_);
      if (value_ != null)
      {
        break;
      }
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