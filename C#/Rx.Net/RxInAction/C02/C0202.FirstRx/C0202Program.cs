using C0203.Shared;
using static System.Console;

namespace C0202.FirstRx;

public class Program
{
  private static StockTicker? _stockTicker;

  static void Main()
  {
    _stockTicker = new StockTicker();

    // Rx StockMonitor - uses Rx to consume and process the stock ticks
    var stockMonitor_ = new RxStockMonitor(_stockTicker);

    ShowMenu();

    GC.KeepAlive(stockMonitor_);
    WriteLine("Press <enter> to continue...");
    ReadLine();
    WriteLine("Bye Bye");
  }

  private static void ShowMenu()
  {
    WriteLine("Choose a simulation type (or x to exit):");
    WriteLine("1) Manual     - you enter the symbol and price");
    WriteLine("2) Automatic  - the system emits and updates a predefined collection of ticks");
    WriteLine("3) Concurrent - tests what happens when ticks are emitted concurrently");
    WriteLine("x) Exit");

    var selection_ = ReadLine();
    switch (selection_)
    {
      case "1":
        ManualSimulator(_stockTicker);
        break;
      case "2":
        AutomaticSimulator(_stockTicker);
        break;
      case "3":
        TestConcurrentTicks(_stockTicker);
        break;
      case "x":
        WriteLine("");
        return;
      default:
        WriteLine("Unknown selection");
        return;
    }
  }

  private static void TestConcurrentTicks(StockTicker? stockTicker)
  {
    _ = ThreadPool.QueueUserWorkItem(_ => stockTicker?.Notify(new StockTick { Price = 100, Symbol = "MSFT" }));
    ThreadPool.QueueUserWorkItem(_ => stockTicker?.Notify(new StockTick { Price = 150, Symbol = "INTC" }));
    ThreadPool.QueueUserWorkItem(_ => stockTicker?.Notify(new StockTick { Price = 170, Symbol = "MSFT" }));
    ThreadPool.QueueUserWorkItem(_ => stockTicker?.Notify(new StockTick { Price = 195.5M, Symbol = "MSFT" }));
  }

  private static void AutomaticSimulator(StockTicker? stockTicker)
  {
    var simulator_ = new StockSimulator(stockTicker);
    simulator_.Run();
  }

  private static void ManualSimulator(StockTicker? stockTicker)
  {
    //////////////////////////////////////////////////////
    // A small program to let you enter the Ticks info. //
    // Symbol X will exit the program                   // 
    //////////////////////////////////////////////////////
    while (true)
    {
      Write("enter symbol (or x to exit): ");
      var symbol = ReadLine();
      if (symbol?.ToLower() == "x")
      {
        break;
      }

      WriteLine("enter price: ");
      decimal price;
      if (decimal.TryParse(ReadLine(), out price))
      {
        stockTicker?.Notify(new StockTick { Price = price, Symbol = symbol });
      }
      else
      {
        WriteLine("price should be decimal");
      }
    }
  }
}