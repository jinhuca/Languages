using static System.Console;

namespace P030;

file class P030Program
{
  static void Main()
  {
    var numbers_ = new MySequenceOfNumbers();
    numbers_.Subscribe(
      value => WriteLine($"Received value: {value}"),
      exception => WriteLine($"Sequence faulted with {exception}"),
      () => WriteLine("Sequence terminated."));
    Read();
  }
}

file sealed class MySequenceOfNumbers : IObservable<int>
{
  public IDisposable Subscribe(IObserver<int> observer)
  {
    observer.OnNext(1);
    observer.OnNext(2);
    observer.OnNext(3);
    observer.OnCompleted();
    return System.Reactive.Disposables.Disposable.Empty;
  }
}
