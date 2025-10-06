using System.Reactive.Linq;
using System.Reactive.Subjects;
using Helpers;

namespace P173;

internal class P173Program
{
  static void Main(string[] args)
  {
    //SimplyPublish();
    //ObserveColdObservable();
    //TurnColdToHotObservable();
    //zipped();
    //publishedZipped();
    //PublishLast();
    Replay();
  }

  static void SimplyPublish()
  {
    var coldObservable = Observable.Interval(TimeSpan.FromSeconds(1)).Take(3);
    var connectableObservable = coldObservable.Publish(0);
    connectableObservable.SubscribeConsole("1");
    connectableObservable.SubscribeConsole("2");
    connectableObservable.Connect();
    Thread.Sleep(2000);
    connectableObservable.SubscribeConsole("3");
    Console.ReadLine();
  }

  static void ObserveColdObservable()
  {
    IObservable<long> coldObservable = Observable.Interval(TimeSpan.FromSeconds(1)).Take(5);
    coldObservable.SubscribeConsole("First");
    coldObservable.SubscribeConsole("Second");
    Thread.Sleep(5000);
    coldObservable.SubscribeConsole("Third");
    Console.ReadLine();
  }

  static void TurnColdToHotObservable()
  {
    IObservable<long> coldObservable = Observable.Interval(TimeSpan.FromSeconds(1)).Take(5);
    IConnectableObservable<long> connectableObservable = coldObservable.Publish();
    connectableObservable.SubscribeConsole("First");
    connectableObservable.SubscribeConsole("Second");
    connectableObservable.Connect();
    Thread.Sleep(6000);
    connectableObservable.SubscribeConsole("Third");
    Console.ReadLine();
  }

  static void zipped()
  {
    int i = 0;
    var numbers = Observable.Range(1, 5).Select(_ => i++);
    numbers.SubscribeConsole("numbers");
    Console.ReadLine();

    var zipped_ = numbers.Zip(numbers, (a, b) => a + b)
      .SubscribeConsole("zipped");
    Console.ReadLine();
  }

  static void publishedZipped()
  {
    var numbers = Observable.Range(1, 5);
    var publishedZip = numbers
      .Publish(published => published.Zip(published, (a, b) => a + b));
    publishedZip.SubscribeConsole("publishedZipped");
  }

  static void PublishLast()
  {
    var coldObservable = Observable.Timer(TimeSpan.FromSeconds(2)).Select(_=>"rx");
    var connectableObservable = coldObservable.PublishLast();
    connectableObservable.SubscribeConsole("First");
    connectableObservable.Connect();
    Thread.Sleep(4000);
    connectableObservable.SubscribeConsole("second");
    Console.ReadLine();
  }

  static void Replay()
  {
    var publishedObservable = Observable
      .Interval(TimeSpan.FromSeconds(1))
      .Take(5)
      .Replay(2);
    publishedObservable.Connect();
    var sub1 = publishedObservable.SubscribeConsole("First");
    Thread.Sleep(3000);
    var sub2 = publishedObservable.SubscribeConsole("Second");
    Console.ReadLine();
  }
}