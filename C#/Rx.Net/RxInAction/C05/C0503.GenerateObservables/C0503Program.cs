using System.Reactive.Disposables;
using System.Reactive.Linq;
using Helpers;

namespace C0503.GenerateObservables;

internal class C0503Program
{
  static void Main(string[] args)
  {
    var generator_ = new MagicalPrimeGenerator();
    var subscription_ = generator_
      .GeneratePrimes(5)
      .Timestamp()
      .SubscribeConsole("primes observable");
      //.Subscribe(x =>
      //{
      //  Console.WriteLine(x.Value + " - " + x.Timestamp);
      //});

    Console.WriteLine("Generation is done");
    Console.ReadLine();
  }
}

public class MagicalPrimeGenerator
{
  public IObservable<int> GeneratePrimes(int amount)
  {
    return Observable.Create<int>(o =>
    {
      foreach (var prime_ in Generate(amount))
      {
        o.OnNext(prime_);
      }
      o.OnCompleted();
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