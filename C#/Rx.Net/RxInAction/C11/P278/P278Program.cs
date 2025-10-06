using System.Reactive.Linq;
using Helpers;

namespace P278;

internal class P278Program
{
  static void Main(string[] args)
  {
    Slowdown1();
  }

  static void Slowdown1()
  {
    var fast = Observable.Interval(TimeSpan.FromSeconds(1)).Select(x => x * 10);
    var slow = Observable.Interval(TimeSpan.FromSeconds(2));
    var zipped = slow.Zip(fast, (x, y) => x + y);
    var subscription = zipped.SubscribeConsole("slowDown");
    Console.ReadLine();
    subscription.Dispose();
  }
}