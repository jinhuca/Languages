using System.Reactive.Linq;
using Helpers;

namespace P170;

internal class P170Program
{
  static async Task Main()
  {
    await ColdObservableMultipleSubscription();
  }

  static async Task ColdObservableMultipleSubscription()
  {
    var coldObservable = Observable.Create<string>(async o =>
    {
      o.OnNext("Hello");
      await Task.Delay(TimeSpan.FromSeconds(1));
      o.OnNext("Rx");
    });
    coldObservable.SubscribeConsole("o1");
    await Task.Delay(TimeSpan.FromSeconds(0.5));
    coldObservable.SubscribeConsole("o2");

    // Waiting for the observable sequence to complete
    //Thread.Sleep(3000);
    Console.ReadLine();
  }
}