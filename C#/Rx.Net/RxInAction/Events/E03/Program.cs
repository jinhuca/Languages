namespace E03;

internal class Program
{
  static void Main(string[] args)
  {
    var generator = new StockTickGenerator();
    generator.UpdatePrices();
    Console.ReadLine();
  }
}