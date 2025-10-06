namespace C0501MagicPrimeGeneratorExample
{
  internal class C0501Program
  {
    static async Task Main(string[] args)
    {
      //GenerateExample1();
      //GenerateExample2();
      await GenerateExample3();
    }

    static void GenerateExample1()
    {
      var generator = new MagicPrimeGenerator();
      foreach (var prime in generator.GenerateWithoutYieldReturn(5))
      {
        Console.WriteLine($"{prime}");
      }
    }

    static void GenerateExample2()
    {
      var generator = new MagicPrimeGenerator();
      foreach (var prime in generator.GenerateWithYieldReturn(5))
      {
        Console.WriteLine($"{prime}");
      }
    }

    static async Task GenerateExample3()
    {
      var generator = new MagicPrimeGenerator();
      foreach (var prime in await generator.GenerateAsync(5))
      {
        Console.WriteLine($"{prime}");
      }
    }
  }
}
