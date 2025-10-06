using static System.Console;

namespace C0113NullCoalese;

internal class C0113Program
{
  static void Main(string[] args)
  {
    string s = null;
    s ??= "Hello, world";
    WriteLine(s);
  }
}