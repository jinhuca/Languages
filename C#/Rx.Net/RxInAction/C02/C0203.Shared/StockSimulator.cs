using static System.Console;

namespace C0203.Shared;

/// <summary>
/// This simulator will emit a batch of StockTicks every two seconds.
/// each time, a single item will be selected and updated with a "drastic change" (more than 10%)
/// </summary>
public class StockSimulator(StockTicker? ticker)
{
  private IEnumerable<StockTick> _ticks = new[]
  {
    new StockTick { Symbol = "MSFT", Price = 53M },
    new StockTick { Symbol = "INTC", Price = 32M },
    new StockTick { Symbol = "ORCL", Price = 41M },
    new StockTick { Symbol = "CSCO", Price = 28M },
  };
  private int _itemToDrasticUpdate;

  public void Run()
  {
    Task.Run(() =>
    {
      while(true)
      {
        UpdatePrices();
        PrintPrices();
        Emit();
        Thread.Sleep(3000);
      }
    });
  }

  private void Emit()
  {
    WriteLine("Emitting...");
    foreach(var stockTick in _ticks)
    {
      ticker?.Notify(stockTick);
    }
  }

  private void PrintPrices()
  {
    WriteLine("Next series to emit:");
    WriteLine("\t");
    foreach(var stockTick in _ticks)
    {
      WriteLine($"{{{stockTick.Symbol} - {stockTick.Price:#.##}}}, ");
    }
    WriteLine();
  }

  private void UpdatePrices()
  {
    _ticks = _ticks
      .Select((tick, i) => {
        var changePercentage = _itemToDrasticUpdate == i ? 1.2M : 1.1M; 
        return new StockTick { Price = tick.Price * changePercentage, Symbol = tick.Symbol };
      })
      .ToList();

    _itemToDrasticUpdate++;
    _itemToDrasticUpdate %= _ticks.Count();
  }
}