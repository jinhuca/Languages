using System.Reactive.Disposables;
namespace P090;

/// <summary>
/// Method 1 - Class implementing IObservable<T> with injected IObserver<T>
/// </summary>
internal sealed class NumbersObservable(int amount) : IObservable<int>
{
  public IDisposable Subscribe(IObserver<int> observer)
  {
    for(var i = 0; i < amount; i++)
    {
      observer.OnNext(i);
    }
    observer.OnCompleted();
    return Disposable.Empty;
  }
}