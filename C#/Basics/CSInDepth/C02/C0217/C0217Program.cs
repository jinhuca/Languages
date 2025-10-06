namespace C0217;

internal class C0217Program
{
  static void Main()
  {
    IEnumerable<string> enumerable_ = Iterator();
    using (IEnumerator<string> enumerator_ = enumerable_.GetEnumerator())
    {
      while (enumerator_.MoveNext())
      {
        string value_ = enumerator_.Current;
        Console.WriteLine("Received value: {0}", value_);
        if (value_ != null)
        {
          break;
        }
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