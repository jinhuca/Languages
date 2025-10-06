using System.Reactive.Disposables;
using System.Reactive.Linq;

namespace C0502GenerateObservable;

internal class MagicPrimeGenerator
{
  public IObservable<int> GeneratePrimesWithCreate(int amount)
  {
    return Observable.Create<int>(observer =>
    {
      foreach (var prime in Generate(amount))
      {
        observer.OnNext(prime);
      }

      observer.OnCompleted();
      return Disposable.Empty;
    });
  }

  public IObservable<int> GeneratePrimesWithTask(int amount)
  {
    var cts = new CancellationTokenSource();
    return Observable.Create<int>(observer =>
    {
      Task.Run(() =>
      {
        foreach (var prime in Generate(amount))
        {
          cts.Token.ThrowIfCancellationRequested();
          observer.OnNext(prime);
        }
        observer.OnCompleted();
      }, cts.Token);
      return new CancellationDisposable(cts);
    });
  }

  private IEnumerable<int> Generate(int amount)
  {
    for (int i = 0; i < amount; ++i)
    {
      yield return GeneratePrime(i);
    }
  }

  private int GeneratePrime(int index)
  {
    Thread.Sleep(1000);

    var firstNumbers = new[] { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, };
    if(index < firstNumbers.Length)
    {
      return firstNumbers[index];
    }

    return firstNumbers.Last();
  }
}