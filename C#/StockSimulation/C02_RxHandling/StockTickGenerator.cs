using System.Diagnostics.CodeAnalysis;
using static System.Console;

namespace C02_RxHandling;

internal class StockTickGenerator(StockTick? ticker) {
  private IEnumerable<Stock> _ticks = [
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
    var rnd_ = new Random();
    var next1_ = (decimal)(rnd_.Next(0, 21) / 100.0);
    var next2_ = (decimal)(rnd_.Next(-20, 0) / 100.0);
    _ticks = _ticks
      .Select((tick, i) => {
        var changePercentage_ = _itemToDrasticUpdate != i ? next1_ : next2_;
        var stock_ = new Stock {
          Symbol = tick.Symbol,
          Price = tick.Price * (1 + changePercentage_)
        };
        return stock_;
      })
      .ToList();

    _itemToDrasticUpdate++;
    _itemToDrasticUpdate %= _ticks.Count();
  }

  private void PrintStocks() {
    WriteLine("New Stock Series:\t");
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