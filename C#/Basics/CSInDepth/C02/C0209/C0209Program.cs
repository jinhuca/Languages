using System.Runtime.CompilerServices;

namespace C0209;

internal class C0209Program
{
  static void Main(string[] args)
  {
    NullableValueDemo();
  }

  static void NullableValueDemo()
  {
    Nullable<int> noValue = new Nullable<int>();
    object noValueBoxed = noValue;
    Console.WriteLine(noValueBoxed == null);

    Nullable<int> someValue = new Nullable<int>(5);
    object someValueBoxedBoxed = someValue;
    Console.WriteLine(someValueBoxedBoxed);
  }
}