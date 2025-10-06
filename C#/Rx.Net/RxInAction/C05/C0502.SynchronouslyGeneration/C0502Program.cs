using C0502.SynchronouslyGeneration;

var generator = new MagicalPrimeGenerator();
foreach (var prime in generator.Generate(5))
{
  Console.WriteLine($"{prime}");
}