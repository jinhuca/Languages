namespace C0127
{
  internal class C0127Program
  {
    static void Main(string[] args)
    {
      System.Text.StringBuilder sb = null;
      string result = sb?.ToString(); // result is null
      Console.WriteLine(result);

      Console.WriteLine(TimesTwo(4));
      Console.WriteLine(SomeProperty);
      Console.WriteLine(TimeCreated);

      var dict = new Dictionary<int, string>()
      {
        [3] = "three",
        [10] = "ten"
      };

      Console.WriteLine(dict[3]);
      Console.WriteLine(dict[10]);

      string s = $"It is {DateTime.Now.DayOfWeek} today";
      Console.WriteLine(s);
    }

    public static int TimesTwo(int x) => x * 2;
    public static string SomeProperty => "Property value";
    public static DateTime TimeCreated { get; } = DateTime.Now;
  }
}
