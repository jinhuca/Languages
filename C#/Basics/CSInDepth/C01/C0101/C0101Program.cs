using System.Collections.Concurrent;
using static System.Console;

namespace C1101;

internal class C0101Program
{
  static void Main()
  {
    //WriteLine(NullableRef("h", null));
    //AnonymousTypeDemo();
    //WriteLine(tupleDemo().name + " - " + tupleDemo().age);
    ConcurrencyDic();
  }

  private static string NullableRef(string x, string? y)
  {
    return y == null ? x + string.Empty : x + y;
  }

  private static void AnonymousTypeDemo()
  {
    var book = new { Title = "Lost in the Snow", Author = "Holly Webb" };
    var title = book.Title;
    var author = book.Author;
    WriteLine(title);
    WriteLine(author);
  }

  private static void demo()
  {
    Dictionary<string, string> map1 = new Dictionary<string, string>();
    var map2 = new Dictionary<string, string>();
    Dictionary<string, string> map3 = new();
  }

  static (string name, int age) tupleDemo()
  {
    return (name: "John", age: 33);
  }

  static void ConcurrencyDic()
  {
    var dictionary = new ConcurrentDictionary<int, string>();
    var newValue = dictionary.AddOrUpdate(0, key => "Zero", (key, oldValue) => "Zero");
    WriteLine(newValue);
  }
}