using System.Reactive.Disposables;
using System.Reactive.Linq;
using System.Reactive.Subjects;
using System.Reactive.Threading.Tasks;
using Helpers;
using static System.String;

namespace P206;

internal class Program
{
  static void Main(string[] args)
  {
    //ZipObservables();
    //CombineLatest1();
    //CombineLatest2();
    CombineLatest3();
    //Concatenation();
    //Merge();
    //Merge1();
  }

  static void ZipObservables()
  {
    IObservable<double> temps1 = new List<double> { 23.1, 22.5, 12.3 }.ToObservable();
    IObservable<double> temps2 = new List<double> { 12.2, 22.1, -10.2 }.ToObservable();
    var temp = temps1
      .Zip(temps2, (t1, t2) => (t1 + t2) / 2)
      .SubscribeConsole("average temps");
  }

  static void CombineLatest1()
  {
    var xs = Observable.Create<int>(observer =>
    {
      observer.OnNext(1);
      observer.OnNext(2);
      observer.OnNext(3);
      observer.OnCompleted();
      return Disposable.Empty;
    });

    var ys = Observable.Create<int>(observer =>
    {
      observer.OnNext(10);
      observer.OnNext(20);
      observer.OnCompleted();
      return Disposable.Empty;
    });

    var subscription_ = xs.CombineLatest(ys, (x, y) => (x + y))
      .SubscribeConsole("CombineLatest-");
    Console.ReadLine();
    subscription_.Dispose();
  }

  static void CombineLatest2()
  {
    var xs = Observable.Create<int>(observer =>
    {
      observer.OnNext(1);
      observer.OnNext(2);
      observer.OnNext(3);
      observer.OnCompleted();
      return Disposable.Empty;
    });

    var ys = Observable.Create<int>(observer =>
    {
      observer.OnNext(10);
      observer.OnNext(20);
      observer.OnCompleted();
      return Disposable.Empty;
    });

    var subscription_ = xs.StartWith(0)
      .CombineLatest(ys.StartWith(0), (s, h) => (s + h))
      .SubscribeConsole("c");
    Console.ReadLine();
    subscription_.Dispose();
  }

  static void CombineLatest3()
  {
    Subject<int> heartRate = new Subject<int>();
    Subject<int> speed = new Subject<int>();
    speed
      .CombineLatest(heartRate, (s, h) => $"Heart: {h} Speed: {s}")
      .SubscribeConsole("Metrics");

    heartRate.OnNext(150);
    heartRate.OnNext(151);
    heartRate.OnNext(152);
    speed.OnNext(30);
    speed.OnNext(31);
    heartRate.OnNext(153);
    heartRate.OnNext(154);
  }

  static void Concatenation()
  {
    Task<string[]> facebookMessages = Task
      .Delay(1000)
      .ContinueWith(_ => new[] { "Facebook1", "Facebook2" });
    Task<string[]> twitterStatuses = Task
      .FromResult(new[] { "Twitter1", "Twitter2" });
    
    Observable.Concat(facebookMessages.ToObservable(), twitterStatuses.ToObservable())
      .SelectMany(message => message)
      .SubscribeConsole("Concat Messages");
    Console.ReadLine();
  }

  static void Merge()
  {
    Task<string[]> facebookMessages = Task
      .Delay(100)
      .ContinueWith(_ => new[] { "Facebook1", "Facebook2" });
    Task<string[]> twitterStatuses = Task
      .FromResult(new[] { "Twitter1", "Twitter2" });

    facebookMessages.ToObservable()
      .Merge(twitterStatuses.ToObservable())
      .SelectMany(message => message)
      .SubscribeConsole("Merged Messages");
    Console.ReadLine(); 
  }

  static void Merge1()
  {
    var observable1 = Observable.Create<int>(observer =>
    {
      observer.OnNext(1);
      Task.Delay(100);
      observer.OnNext(2);
      Task.Delay(100);
      observer.OnNext(3);
      Task.Delay(100);
      observer.OnCompleted();
      return Disposable.Empty;
    });

    var observable2 = Observable.Create<int>(observer =>
    {
      //Task.Delay(100);
      observer.OnNext(10);
      Task.Delay(100);
      observer.OnNext(20);
      Task.Delay(100);
      observer.OnCompleted();
      return Disposable.Empty;
    });

    var subscription = observable1.Merge(observable2)
      .SubscribeConsole("Merged");
    Console.ReadLine();
    subscription.Dispose();

    Task<int[]> first = Task.Delay(100)
      .ContinueWith(_ => new[] { 1 })
      .ContinueWith(_ =>
      {
        Task.Delay(100);
        return new[] { 2 };
      })
      .ContinueWith(_=>
      {
        Task.Delay(100);
        return new[] { 3 };
      });
    Task<int[]> second = Task.FromResult(new[] { 10, 20 });
    Observable.Merge(first.ToObservable(), second.ToObservable())
      .SelectMany(i=>i)
      .SubscribeConsole("Merged");
    Console.ReadLine();
  }
}