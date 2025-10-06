using System.Reactive.Disposables;
using System.Reactive.Linq;
using static System.Console;

namespace P043;

internal class P043Program
{
  static void Main()
  {
    Return(1).Subscribe(WriteLine);
    Empty<int>().Subscribe(WriteLine);
    Never<int>().Subscribe(WriteLine);
    Throws<int>(new Exception()).Subscribe(
      WriteLine,
      e => WriteLine(e));
  }
  
  public static IObservable<T> Return<T>(T value)
  {
    return Observable.Create<T>(obj =>
    {
      obj.OnNext(value);
      obj.OnCompleted();
      return Disposable.Empty;
    });
  }

  public static IObservable<T> Empty<T>()
  {
    return Observable.Create<T>(obj =>
    {
      obj.OnCompleted();
      return Disposable.Empty;
    });
  }
  
  public static IObservable<T> Never<T>()
  {
    return Observable.Create<T>(obj => Disposable.Empty);
  }

  public static IObservable<T> Throws<T>(Exception exception)
  {
    return Observable.Create<T>(obj =>
    {
      obj.OnError(exception);
      return Disposable.Empty;
    });
  }
}