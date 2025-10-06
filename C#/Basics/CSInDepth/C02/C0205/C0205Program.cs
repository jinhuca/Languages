namespace C0205;

internal class C0205Program
{
  static void Main(string[] args)
  {
    var source_ = new List<int>() { 1, 2, 3, 4, 5 };
    Console.WriteLine(LastOrDefault(source_));
  }

  static T LastOrDefault<T>(IEnumerable<T> source)
  {
    var ret_ = default(T);
    foreach (var item_ in source)
    {
      ret_ = item_;
    }

    return ret_;
  }
}