using System;
using System.Collections.Generic;
using System.Linq;
using System.Reactive.Linq;
using System.Text;
using System.Threading.Tasks;

namespace C0503GenerateAsyncCreate;

internal class MagicPrimeGenerator
{
  public IObservable<int> GeneratePrimes(int amount)
  {
    return Observable.Create<int>((observer, cancellationToken) =>
    {
      return Task.Run(() =>
      {
        foreach (var prime in Generate(amount))
        {
          cancellationToken.ThrowIfCancellationRequested();
          observer.OnNext(prime);
        }
        observer.OnCompleted();
      });
    });
  }

  private IEnumerable<int> Generate(int amount)
  {
    for(int i = 0; i < amount; ++i)
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