using System.Reactive.Disposables;
using System.Reactive.Linq;
using static System.Console;

namespace P056;

internal class P056Program
{
  static void Main()
  {
    var source_ = new List<string> { "hello", "Rx" };
    source_.ToObservableOverSimplified().Subscribe(
      WriteLine,
      () => WriteLine("-- completed --"));
    ReadKey();
  }
}

public static class ToObservableExtension
{
  public static IObservable<T> ToObservableOverSimplified<T>(this IEnumerable<T> source)
  {
    return Observable.Create<T>(o =>
    {
      foreach(var item in source)
      {
        o.OnNext(item);
      }

      o.OnCompleted();

      // Incorrectly ignored unsubscribing
      return Disposable.Empty;
    });
  }
}