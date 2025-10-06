using System.Reactive;
using System.Reactive.Disposables;
using static System.Console;

namespace P093SimplestObservableBase;

internal class P093SimplestProgram
{
  static void Main(string[] args)
  {
    var sub = new DerivedObservable().Subscribe(WriteLine);
    ReadLine();
    sub.Dispose();
  }
}

internal class DerivedObservable : ObservableBase<string>
{
  protected override IDisposable SubscribeCore(IObserver<string> observer)
  {
    observer.OnNext("hello");
    observer.OnCompleted();
    observer.OnNext("bye");       // this is not going pushed to observer since it is invoked after OnCompleted().
    return Disposable.Empty;
  }
}