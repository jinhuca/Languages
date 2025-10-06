using System.Reactive.Concurrency;
using System.Reactive.Disposables;
using System.Reactive.Linq;
using Helpers;

namespace P252;

internal class P252Program
{
  static void Main(string[] args)
  {
    SubscribeOnDemo1();
  }

  static void SubscribeOnDemo1()
  {
    var eventLoopScheduler = new EventLoopScheduler();
    var subscription = Observable
      .Interval(TimeSpan.FromSeconds(1))
      .Do(x => Console.WriteLine("Inside Do"))
      .SubscribeOn(eventLoopScheduler)
      .SubscribeConsole();

    eventLoopScheduler.Schedule(1,
      (s, state) =>
      {
        Console.WriteLine("Before sleep");
        Thread.Sleep(TimeSpan.FromSeconds(3));
        Console.WriteLine("After sleep");
        return Disposable.Empty;
      });
    Console.ReadLine();
    subscription.Dispose();
    Console.WriteLine("Subscription disposed");
  }
}