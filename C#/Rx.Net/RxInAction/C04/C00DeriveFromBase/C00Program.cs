using System.Reactive;
using System.Reactive.Disposables;

namespace C00DeriveFromBase;

internal class C00Program
{
  static void Main(string[] args)
  {
    var gen = new Fibonacci(10);
    var sub = gen.Subscribe(Console.WriteLine);
    Console.ReadLine();
    sub.Dispose();

  }
}

internal class Fibonacci : ObservableBase<int>
{
  private readonly int _count = 0;

  public Fibonacci(int count)
  {
    _count = count;
  }

  protected override IDisposable SubscribeCore(IObserver<int> observer)
  {
    foreach(var i in Generate().Take(_count))
    {
      observer.OnNext(i);
    }
    observer.OnCompleted();
    observer.OnNext(999);
    return Disposable.Create(Console.WriteLine);
  }

  private IEnumerable<int> Generate()
  {
    int a = 0;
    int b = 1;
    yield return a;
    yield return b;
    while(true)
    {
      b = a + b;
      a = b - a;
      yield return b;
    }
  }
}