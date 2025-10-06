using System.Reactive.Concurrency;
using System.Reactive.Linq;
using Helpers;

namespace P254;

internal class P254Program
{
  static void Main(string[] args)
  {
    SubscribeOnAndObserveOn();
  }

  static void SubscribeOnAndObserveOn()
  {
    new[] { 0, 1, 2, 3, 4, 5 }.ToObservable()
      .Take(3).LogWithThread("A")
      .Where(x => x % 2 == 0).LogWithThread("B")
      .SubscribeOn(NewThreadScheduler.Default).LogWithThread("C")
      .Select(x => x * x).LogWithThread("D")
      .ObserveOn(TaskPoolScheduler.Default).LogWithThread("E")
      .SubscribeConsole("Squares by time");
    Console.ReadLine();
  }
}