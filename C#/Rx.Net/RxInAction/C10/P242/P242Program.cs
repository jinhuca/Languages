using System.Reactive.Linq;
using Helpers;

namespace P242;

internal class P242Program
{
  static void Main(string[] args)
  {
    //TimestampDemo();
    //TimeIntervalDemo();
    //TimeOutDemo();
    //DelayDemo();
    //DelayDemo2();
    //ThrottleDemo();
    //ThrottleDemo2();
    SampleDemo();
  }

  static void TimestampDemo()
  {
    IObservable<long> deviceHeartbeat = Observable.Interval(TimeSpan.FromSeconds(1));
    var subscription = deviceHeartbeat
      .Take(3)
      .Timestamp()
      .SubscribeConsole("Heartbeat");
    Console.ReadLine();
    subscription.Dispose();
  }

  static void TimeIntervalDemo()
  {
    var deviceHeartbeat = Observable
      .Timer(TimeSpan.FromSeconds(1))
      .Concat(Observable.Timer(TimeSpan.FromSeconds(2)))
      .Concat(Observable.Timer(TimeSpan.FromSeconds(4)));

    var subscription = deviceHeartbeat
      .TimeInterval()
      .SubscribeConsole("time from last heartbeat");
    Console.ReadLine();
    subscription.Dispose();
  }

  static void TimeOutDemo()
  {
    var observable = Observable
      .Timer(TimeSpan.FromSeconds(1))
      .Concat(Observable.Timer(TimeSpan.FromSeconds(1)))
      .Concat(Observable.Timer(TimeSpan.FromSeconds(4)))
      .Concat(Observable.Timer(TimeSpan.FromSeconds(4)));

    var subscription = observable
      .Timeout(TimeSpan.FromSeconds(3))
      .SubscribeConsole("Timeout");
    Console.ReadLine();
    subscription.Dispose();
  }

  static void DelayDemo()
  {
    var observable = Observable
      .Timer(TimeSpan.FromSeconds(1))
      .Concat(Observable.Timer(TimeSpan.FromSeconds(1)))
      .Concat(Observable.Timer(TimeSpan.FromSeconds(4)))
      .Concat(Observable.Timer(TimeSpan.FromSeconds(4)));

    var subscription = observable
      .Timestamp()
      .Delay(TimeSpan.FromSeconds(2))
      .Timestamp()
      .Take(5)
      .SubscribeConsole("Delay");

    Console.ReadLine();
    subscription.Dispose();
  }

  static void DelayDemo2()
  {
    var observable = new[] { 4, 1, 2, 3 }.ToObservable();
    observable
      .Timestamp()
      .Delay(x => Observable.Timer(TimeSpan.FromSeconds(x.Value)))
      .Timestamp()
      .SubscribeConsole("Delay");
    Console.ReadLine();
  }

  static void ThrottleDemo()
  {
    var observable = Observable
      .Return("Update A")
      .Concat(Observable.Timer(TimeSpan.FromSeconds(2)).Select(_ => "Update B"))
      .Concat(Observable.Timer(TimeSpan.FromSeconds(1)).Select(_ => "Update C"))
      .Concat(Observable.Timer(TimeSpan.FromSeconds(1)).Select(_ => "Update D"))
      .Concat(Observable.Timer(TimeSpan.FromSeconds(3)).Select(_ => "Update E"));

    var subscription = observable
      .Throttle(TimeSpan.FromSeconds(2))
      .SubscribeConsole("Throttle");

    Console.ReadLine();
  }

  static void ThrottleDemo2()
  {
    var observable = Observable
      .Return("Msg A")
      .Concat(Observable.Timer(TimeSpan.FromSeconds(2)).Select(_ => "Msg B"))
      .Concat(Observable.Timer(TimeSpan.FromSeconds(1)).Select(_ => "Immediate Update"))
      .Concat(Observable.Timer(TimeSpan.FromSeconds(1)).Select(_ => "Msg D"))
      .Concat(Observable.Timer(TimeSpan.FromSeconds(3)).Select(_ => "Msg E"));

    var subscription = observable
      .Throttle(x => x == "Immediate Update" ? Observable.Empty<long>() : Observable.Timer(TimeSpan.FromSeconds(2)))
      .SubscribeConsole("Variable Throttle");
    Console.ReadLine();
  }

  static void SampleDemo()
  {
    Observable.Interval(TimeSpan.FromSeconds(1))
      .Sample(TimeSpan.FromSeconds(3.5))
      .Take(3)
      .SubscribeConsole("Sample");
    Console.ReadLine();
  }
}