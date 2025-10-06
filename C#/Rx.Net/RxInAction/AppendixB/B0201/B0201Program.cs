using System.Reactive.Disposables;
using System.Reactive.Linq;

namespace B0201;

internal class B0201Program
{
  static void Main()
  {
    Console.WriteLine("Hello, World!");
  }

  public static IObservable<T> Return<T>(T value)
  {
    return Observable.Create<T>(o =>
    {
      o.OnNext(value);
      o.OnCompleted();
      return Disposable.Empty;
    });
  }
}