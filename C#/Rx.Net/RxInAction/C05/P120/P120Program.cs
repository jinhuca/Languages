using System.Reactive.Linq;

namespace P120;

internal class P120Program
{
  static void Main()
  {
    foreach (var prime in MagicalPrimeGenerator.GeneratePrimesAsync(5))
    {
      Console.WriteLine(prime);
    }
  }
}

internal static class MagicalPrimeGenerator
{
  public static IObservable<int> GeneratePrimesAsync(int amount)
  {
    return Observable.Create<int>((o, ct) =>
    {
      return Task.Run(() =>
      {
        foreach (var prime in Generate(amount))
        {
          ct.ThrowIfCancellationRequested();
          o.OnNext(prime);
        }
        o.OnCompleted();
      }, ct);
    });
  }

  private static IEnumerable<int> Generate(int amount)
  {
    for (int i = 0; i < amount; i++)
    {
      yield return GeneratePrime(i);
    }
  }

  private static int GeneratePrime(int index)
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