namespace P117
{
  internal class P117Program
  {
    static async Task Main()
    {
      GenerateSynchronously();
      await GenerateAsynchronously();
    }

    static void GenerateSynchronously()
    {
      var generator = new MagicalPrimeGenerator();
      foreach (var prime in generator.Generate(5))
      {
        Console.WriteLine($"{prime}");
      }
    }

    static async Task GenerateAsynchronously()
    {
      Console.WriteLine("it will takes a 10 seconds before anything will be printed");
      var generator = new MagicalPrimeGenerator();
      foreach (var prime in await generator.GenerateAsync(5))
      {
        Console.Write($"{prime}");
      }
    }
  }

  internal class MagicalPrimeGenerator
  {
    public async Task<IReadOnlyCollection<int>> GenerateAsync(int amount)
    {
      return await Task.Run(() => Generate(amount).ToList().AsReadOnly());
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
}