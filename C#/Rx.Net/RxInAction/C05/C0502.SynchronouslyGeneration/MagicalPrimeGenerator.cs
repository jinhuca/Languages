namespace C0502.SynchronouslyGeneration;

internal class MagicalPrimeGenerator
{
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
    var firstNumbers = new[] { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29 };
    if (index < firstNumbers.Length)
    {
      return firstNumbers[index];
    }

    return firstNumbers.Last();
  }
}