using System.Reactive.Disposables;
using System.Reactive.Linq;
using static System.Console;

namespace P118;

internal class P118Program
{
  static void Main(string[] args)
  {
    var generator = new MagicalPrimeGenerator();
    var subscriber = generator
      .GeneratePrimes(5)
      .Timestamp()
      .Subscribe(item =>
      {
        WriteLine($"{item.Value} @ {item.Timestamp}");
      });
  }
}

internal class MagicalPrimeGenerator
{
  public IObservable<int> GeneratePrimes(int amount)
  {
    return Observable.Create<int>(item =>
    {
      foreach (var prime in Generate(amount))
      {
        item.OnNext(prime);
      }
      item.OnCompleted();

      return Disposable.Empty;
    });
  }

  public IEnumerable<int> Generate(int amount)
  {
    for (int i = 0; i < amount; i++)
    {
      yield return GeneratePrime(i);
    }
  }

  int GeneratePrime(int index)
  {
    Thread.Sleep(1000);

    var firstNumbers = new[] { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29 };
    if (index < firstNumbers.Length)
    {
      return firstNumbers[index];
    }

    return firstNumbers.Last();
  }
}