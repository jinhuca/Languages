using System.Collections.Concurrent;

namespace C0102;

internal class C0102Program
{
  static readonly ConcurrentDictionary<int, string> dic_ = new();

  static void Main(string[] args)
  {
    var t1 = Task.Run(() =>
    {
      string newValue = dic_.AddOrUpdate(0, key => "Zero", (key, oldValue) => "Zero");
    });

    var t2 = Task.Run(() =>
    {
      string newValue = dic_.AddOrUpdate(1, key => "One", (key, oldValue) => "One");
    });

    Task.WaitAll(t1, t2);

    Console.WriteLine(dic_[0]);
    Console.WriteLine(dic_[1]);
    Console.Read();
  }
}