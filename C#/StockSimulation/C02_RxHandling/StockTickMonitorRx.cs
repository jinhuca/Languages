using System.Reactive.Linq;
using static System.Console;

namespace C02_RxHandling;

internal class StockTickMonitorRx : IDisposable {
  private readonly IDisposable _subscription;
  private const decimal DrasticChangeRatio = 0.1m;
  public IObservable<DrasticChange> DrasticChanges { get; }

  public void Dispose() => _subscription.Dispose();

  public StockTickMonitorRx(StockTick? ticker) {
    IObservable<Stock> ticks_ = Observable
      .FromEventPattern<EventHandler<Stock>, Stock>(
        h => ticker!.StockPriceChanged += h, h => ticker!.StockPriceChanged -= h)
      .Select(tickEvent => tickEvent.EventArgs)
      .Synchronize();

    IObservable<DrasticChange> drasticChanges_ =
      from tick in ticks_
      group tick by tick.Symbol into company
      from tickPair in company.Buffer(2, 1)
      let changeRatio = Math.Abs((tickPair[1].Price - tickPair[0].Price) / tickPair[0].Price)
      where changeRatio >= DrasticChangeRatio
      select new DrasticChange {
        Symbol = company.Key,
        ChangeRatio = changeRatio,
        OldPrice = tickPair[0].Price,
        NewPrice = tickPair[1].Price
      };

    DrasticChanges = drasticChanges_;

    _subscription = DrasticChanges.Subscribe(
      change => {
        WriteLine(
          $"Drastic change detected for {change.Symbol}: " +
          $"{change.OldPrice:F2} -> {change.NewPrice:F2} " +
          $"({change.ChangeRatio:P2})");
      },
      ex => {
        /* code that handles errors */
      },
      () => {
        /* code that runs on completion */
      });
  }
}