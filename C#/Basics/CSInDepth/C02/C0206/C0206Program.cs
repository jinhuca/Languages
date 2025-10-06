namespace C0206;

internal class C0206Program
{
  static void Main(string[] args)
  {
    PrintType<string>();
  }

  static void PrintType<T>()
  {
    Console.WriteLine("typeof(T) = {0}", typeof(T));
    Console.WriteLine("typeof(List<T>) = {0}", typeof(List<T>));
  }
}