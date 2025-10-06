using System.Text;

namespace C0308.Fluent;

internal class C0308Program
{
  static void Main()
  {
    DemoFluent1();
    DemoFluent2();
  }

  static void DemoFluent1()
  {
    var sbuilder_ = new StringBuilder();
    var result_ = sbuilder_
      .AppendLine("Fluent")
      .AppendLine("Interfaces")
      .AppendLine("Are")
      .AppendLine("Awesome")
      .ToString();
    Console.WriteLine(result_);
  }

  static void DemoFluent2()
  {
    var words_ = new List<string>();
    words_
      .AddItems("This")
      .AddItems("Feels")
      .AddItems("Weird");
    Console.WriteLine(string.Join(" ", words_));
  }
}

public static class ListExtensions
{
  public static List<T> AddItems<T>(this List<T> list, T item)
  {
    list.Add(item);
    return list;
  }
}