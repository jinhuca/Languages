using System.Reactive.Disposables;
using System.Reactive.Linq;
using Helpers;
using static System.Console;

namespace P119;

internal class P119Program
{
  static void Main()
  {
    var generator_ = new MagicalPrimeGenerator();
    var subscription_ = generator_
      .GeneratePrimes(5)
      .Timestamp()
      .SubscribeConsole("Prime");
      
    ReadLine();
  }
}

public class MagicalPrimeGenerator
{
  public IObservable<int> GeneratePrimes(int amount)
  {
    var cts_ = new CancellationTokenSource();
    return Observable.Create<int>(o =>
    {
      Task.Run(() =>
      {
        foreach (var prime_ in Generate(amount))
        {
          cts_.Token.ThrowIfCancellationRequested();
          o.OnNext(prime_);
        }
        o.OnCompleted();
      }, cts_.Token);
      return new CancellationDisposable(cts_);
    });
  }

  public IEnumerable<int> Generate(int amount)
  {
    for (int i = 0; i < amount; i++)
    {
      yield return GeneratePrime(i);
    }
  }

  private int GeneratePrime(int index)
  {
    Thread.Sleep(2000);

    var firstNumbers_ = new[] { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29 };
    if (index < firstNumbers_.Length)
    {
      return firstNumbers_[index];
    }

    return firstNumbers_.Last();
  }
}