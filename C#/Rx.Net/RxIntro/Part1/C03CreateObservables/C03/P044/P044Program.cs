using System.Reactive.Linq;
using static System.Console;

namespace P044;

internal class P044Program
{
  static void Main()
  {
    DemoWithDeferal();
    DemoWithoutDeferal();
  }

  static void DemoWithoutDeferal()
  {
    WriteLine("Calling factory method");
    IObservable<int> _s = WithoutDeferal();
    
    WriteLine("First subscription");
    _s.Subscribe(WriteLine);

    WriteLine("Second subscription");
    _s.Subscribe(WriteLine);
  }

  static void DemoWithDeferal()
  {
    WriteLine("Calling factory method");
    IObservable<int> _s = WithDeferral();
    
    WriteLine("First subscription");
    _s.Subscribe(WriteLine);

    WriteLine("Second subscription");
    _s.Subscribe(WriteLine);
  }

  static IObservable<int> WithoutDeferral()
  {
    WriteLine("Doing some startup work...");
    return Observable.Range(1, 3);
  }

  static IObservable<int> WithoutDeferal()
  {
    WriteLine("Doing some startup work ...");
    return Observable.Range(1, 3);
  }

  static IObservable<int> WithDeferral()
  {
    return Observable.Defer(() =>
    {
      WriteLine("Doing some startup work...");
      return Observable.Range(1, 3);
    });
  }
}