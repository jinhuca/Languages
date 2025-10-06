using C0203.Shared;
using System.Reactive.Linq;
using static System.Console;

namespace C0202.FirstRx;

public class RxStockMonitor : IDisposable
{
  private readonly IDisposable _subscription;
  public IObservable<DrasticChange> DrasticChanges { get; }

  internal RxStockMonitor(StockTicker? ticker)
  {
    const decimal maxChangeRatio = 0.1m;

    // creating an observable from the StockTick event,
    // each notification will carry only the EventArgs and will be synchronized.
    IObservable<StockTick> ticks_ = Observable
      .FromEventPattern<EventHandler<StockTick>, StockTick>(
        h => ticker!.StockTick += h, h => ticker!.StockTick -= h)
      .Select(tickEvent => tickEvent.EventArgs)
      .Synchronize();

    IObservable < DrasticChange > drasticChanges_ =
      from tick in ticks_
      group tick by tick.Symbol into company
      from tickPair in company.Buffer(2, 1)
      let changeRatio = Math.Abs((tickPair[1].Price - tickPair[0].Price) / tickPair[0].Price)
      where changeRatio > maxChangeRatio
      select new DrasticChange
      {
        Symbol = company.Key,
        ChangeRatio = changeRatio,
        OldPrice = tickPair[0].Price,
        NewPrice = tickPair[1].Price
      };

    DrasticChanges = drasticChanges_;

    _subscription = drasticChanges_.Subscribe(
      change => {
        WriteLine($"StockTick: {change.Symbol} has changed with {change.ChangeRatio} ratio, " +
                  $"Old Price: {change.OldPrice} New Price: {change.NewPrice}");
      },
      ex => {
        /* code that handles errors */
      },
      () => {
        /* code that handles the observable completeness */
      });
  }

  public void Dispose() => _subscription.Dispose();
}