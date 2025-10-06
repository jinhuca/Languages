using System.Reactive.Linq;
using Helpers;
using static System.Console;
using static System.TimeSpan;

namespace P143;

internal class P143Program
{
  static void Main(string[] args)
  {
    DelaySubscription();
    //Delay();
    //StopAtScheduleTime();
    //Discard();
    //TakeUntilAStopMessage();
  }

  static void DelaySubscription()
  {
    WriteLine($"Creating subscription at {DateTime.Now}");
    Observable.Range(1, 5)
      .Timestamp()
      .DelaySubscription(FromSeconds(5))
      .SubscribeConsole();
    ReadLine();
  }

  static void Delay()
  {
    WriteLine($"Creating the observable pipeline at {DateTime.Now}");
    var observable = Observable
      .Range(1, 5)
      .Timestamp()
      .DelaySubscription(FromSeconds(5));

    Thread.Sleep(FromSeconds(2));

    WriteLine($"Creating subscription at {DateTime.Now}");
    observable.SubscribeConsole();
    ReadLine();
  }

  static void StopAtScheduleTime()
  {
    var subscription = Observable.Timer(DateTimeOffset.Now, TimeSpan.FromSeconds(1))
      .Select(t => DateTimeOffset.Now)
      .TakeUntil(DateTimeOffset.Now.AddSeconds(5))
      .SubscribeConsole("TakeUntil(time)");
    ReadLine();
    subscription.Dispose();
  }

  static void Discard()
  {
    Observable.Timer(DateTimeOffset.Now, TimeSpan.FromSeconds(1))
      .Select(t => DateTimeOffset.Now)
      .TakeUntil(Observable.Timer(TimeSpan.FromSeconds(5)))
      .SubscribeConsole("TakeUntil(observable)");
    ReadLine();
  }

  private static void TakeUntilAStopMessage()
  {
    IObservable<string> message = Observable.Range(1, 5)
      .Select(i => "Message " + i)
      .Concat(Observable.Return("STOP"))
      .Concat(Observable.Return("After Stop"));

    IObservable<string> controlChannel = message;

    message.TakeUntil(controlChannel.Where(m=>m=="STOP")).RunExample("TakeUntil(STOP)");
    ReadLine();
  }
}