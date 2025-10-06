using System.Reactive;
using System.Reactive.Disposables;
using Helpers;

namespace P094ObservableBase;

internal class Program
{
  static void Main(string[] args)
  {
    var observable_ = new NumbersObservableBase(3);
    observable_.Subscribe(new ConsoleObserver<int>("ObservableBase"));
  }
}

internal class NumbersObservableBase : ObservableBase<int>
{
  private readonly int _amount;

  public NumbersObservableBase(int amount)
  {
    _amount = amount;
  }

  protected override IDisposable SubscribeCore(IObserver<int> observer)
  {
    for (int i = 0; i < _amount; i++)
    {
      observer.OnNext(i);
    }
    observer.OnCompleted();
    observer.OnNext(10);
    observer.OnError(new AccessViolationException());
    
    return Disposable.Empty;
  }
}