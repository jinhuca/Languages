using System.Reactive;
using System.Reactive.Linq;

namespace P142;

internal class P142Program
{
  static void Main(string[] args)
  {
    CreateObserverInstance();
    Console.ReadLine();
  }

  static void CreateObserverInstance()
  {
    var observer = Observer.Create<string>(Console.WriteLine);

    Observable.Interval(TimeSpan.FromSeconds(1))
      .Select(x => "X" + x)
      .Subscribe(observer);

    Observable.Interval(TimeSpan.FromSeconds(1))
      .Select(x => "YY" + x)
      .Subscribe(observer);
  }
}