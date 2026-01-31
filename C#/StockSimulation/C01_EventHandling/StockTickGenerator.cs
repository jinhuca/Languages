using System.Diagnostics.CodeAnalysis;
using static System.Console;

namespace C01_EventHandling;

internal class StockTickGenerator(StockTick? ticker) {
  private IEnumerable<StockInfo> _ticks = [
    new() { Symbol = "MSFT", Price = 53M },
    new() { Symbol = "INTC", Price = 32M },
    new() { Symbol = "ORCL", Price = 41M },
    new() { Symbol = "CSCO", Price = 28M }
  ];

  private int _itemToDrasticUpdate;

  [SuppressMessage("ReSharper", "FunctionNeverReturns")]
  public void Run() {
    Task.Run(() => {
      while (true) {
        UpdatePrices();
        PrintStocks();
        Emit();
        Thread.Sleep(5000);
      }
    });
  }

  private void UpdatePrices() {
    _ticks = _ticks
      .Select((tick, i) => {
        var changePercentage_ = _itemToDrasticUpdate == i ? 1.11M : .96M;
        return new StockInfo
        {
          Symbol = tick.Symbol,
          Price = tick.Price * changePercentage_
        };
      })
      .ToList();

    _itemToDrasticUpdate++;
    _itemToDrasticUpdate %= _ticks.Count();
  }

  private void PrintStocks() {
    WriteLine("New StockInfo Series:\t");
    foreach (var tick_ in _ticks) {
      WriteLine($"\t{tick_.Symbol}: {tick_.Price:F2}");
    }
    WriteLine();
  }

  private void Emit() {
    WriteLine("Emitting...");
    foreach (var tick_ in _ticks) {
      ticker?.Notify(tick_);
    }
  }
}