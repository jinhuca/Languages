using System;
using System.Collections.Generic;
using System.Reactive.Linq;
using System.Text;

namespace C03_RxStreams;

internal class StockMonitor : IDisposable {
  private readonly IDisposable _subscription;
  private IObserver<Stock> _observer;
  private IObservable<Stock> _ticks;
  private const decimal DrasticChangeRatio = 0.1m;
  public IObservable<StockDrasticChange> DrasticChanges { get; }

  public void Dispose() => _subscription.Dispose();

  public StockMonitor(IObservable<Stock> source, IObserver<Stock> observer) {
    _ticks = source;
    _observer = observer;

    var _init = new Dictionary<string, StockDrasticChange>()
    {
      {"MSFT", new() { Symbol = "MSFT", ChangeRatio = 0, NewPrice = 0.0M, OldPrice = 51.12M}},
      {"INTC", new() { Symbol = "INTC", ChangeRatio = 0, NewPrice = 0.0M, OldPrice = 32.38M}},
      {"ORCL", new() { Symbol = "ORCL", ChangeRatio = 0, NewPrice = 0.0M, OldPrice = 41.27M}},
      {"CSCO", new() { Symbol = "CSCO", ChangeRatio = 0, NewPrice = 0.0M, OldPrice = 28.65M}}
    };

    var drasticChanges_ = from tick in _ticks
      let change_ = Math.Abs((_init[tick.Symbol!].OldPrice - tick.Price) / _init[tick.Symbol!].OldPrice)
      where change_ >= DrasticChangeRatio
      select new StockDrasticChange()
      {
        Symbol = tick.Symbol,
        ChangeRatio = change_,
        OldPrice = _init[tick.Symbol!].OldPrice,
        NewPrice = tick.Price
      };

    DrasticChanges = drasticChanges_;

    _subscription = DrasticChanges.Subscribe(
      change => {
        Console.WriteLine(
          $"Drastic change detected for {change.Symbol}: " +
          $"{change.OldPrice:F2} -> {change.NewPrice:F2} " +
          $"({change.ChangeRatio:P2})");
      },
      ex => {
        Console.WriteLine(ex.Message);
      },
      () => {
        Console.WriteLine("Monitoring completed.");
      });
  }
}