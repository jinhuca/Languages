using System.Reactive.Linq;
using static System.Console;

namespace P020;

file class P020Program
{
  public static void Main()
  {
    IObservable<long> ticks_ = Observable.Timer(
      dueTime: TimeSpan.Zero,
      period: TimeSpan.FromSeconds(1));

    ticks_.Subscribe(new MyConsoleObserver<long>());
    Read();
  }
}

file class MyConsoleObserver<T> : IObserver<T>
{
  public void OnNext(T value)
  {
    WriteLine($"Received value {value}");
  }

  public void OnError(Exception error)
  {
    WriteLine($"Sequence faulted with {error}");
  }

  public void OnCompleted()
  {
    WriteLine("Sequence terminated");
  }
}