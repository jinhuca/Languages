using System.Reflection;
using static System.Console;

namespace C0501;

internal class C0501Program
{
  public static void Main()
  {
    demo1();

    int[] numbers = new int[10];
    string[] strings = new string[numbers.Length];
    numbers[0] = 42;
    numbers[1] = numbers.Length;
    numbers[2] = numbers[0] + numbers[1];
    numbers[numbers.Length - 1] = 99;

    WriteLine(GetCopyrightForType(numbers));
  }

  private static string GetCopyrightForType(object o)
  {
    Assembly asm = o.GetType().Assembly;
    var copyrightAttribute =
      (AssemblyCopyrightAttribute)asm.GetCustomAttributes(typeof(AssemblyCopyrightAttribute), true)[0];
    return copyrightAttribute.Copyright;
  }

  private static void demo1()
  {
    WriteLine("Enter array size: ");
    int size = Read();
    int[] arr = new int[size];
    arr[0] = 42;
    //arr[1] = 43;
    //arr[2] = 44;
    arr[7] = 90;
    
    foreach (var element in arr)
    {
      WriteLine(element);
    }

    WriteLine($"The size of array is: {arr.Length}");
  }
}