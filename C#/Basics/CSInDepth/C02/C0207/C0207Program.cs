namespace C0207;

internal class C0207Program
{
  static void Main(string[] args)
  {
    GenericCounter<string>.Increment();
    GenericCounter<string>.Increment();
    GenericCounter<string>.Display();
  }
}

class GenericCounter<T>
{
  private static int value;

  static GenericCounter()
  {
    Console.WriteLine("Initializing counter for {0}", typeof(T));
  }

  public static void Increment()
  {
    value++;
  }

  public static void Display()
  {
    Console.WriteLine("Counter for {0}: {1}", typeof(T), value);
  }
}