using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Console;

namespace E03;

internal class StockTickGenerator
{
  private IEnumerable<StockTick> _ticks = new[]
  {
    new StockTick ("MSFT", 53M),
    new StockTick( "INTC", 32M),
    new StockTick ("ORCL", 41M ),
    new StockTick ("CSCO", 28M ),
  };

  private List<StockTickPublisher> _stockTickers = new List<StockTickPublisher>();

  private StockTickPublisher ticker = new StockTickPublisher();

  public void demo()
  {
    ticker.StockTickEvent += Ticker_StockTickEvent1;
    ticker.StockTickEvent += Ticker_StockTickEvent2;

    foreach(var tick in _ticks)
    {
      ticker.StockTick = tick;
    }

    WriteLine();
    //foreach(var ticker in _stockTickers)
    //{
    //  ticker.StockTickEvent += Ticker_StockTickEvent1;
    //}
    Thread.Sleep(1200);
    ticker.StockTick = new StockTick("MSFT", 41m);
    Thread.Sleep(1200);
    ticker.StockTick = new StockTick("INTC", 12M);
    Thread.Sleep(1200);
    ticker.StockTick = new StockTick("INTC", 12M);
  }

  private void Ticker_StockTickEvent1(object? sender, StockTick e)
  {
    ForegroundColor = ConsoleColor.Blue;
    WriteLine($"{e.Symbol} = {e.Price} observed by {nameof(Ticker_StockTickEvent1)}");
    ForegroundColor = default;
  }

  private void Ticker_StockTickEvent2(object? sender, StockTick e)
  {
    ForegroundColor = ConsoleColor.Red;
    WriteLine($"{e.Symbol} = {e.Price} observed by {nameof(Ticker_StockTickEvent2)}");
    ForegroundColor = default;
  }

  private int _itemToDrasticUpdate;

  private void RegisterTickChangedEvent()
  {
    ticker.StockTickEvent += Ticker_StockTickEvent1;
  }

  public void UpdatePrices()
  {
    RegisterTickChangedEvent();
    foreach (var tick in _ticks)
    {
      var changePercentage = 1.2M;
      ticker.StockTick = new StockTick(tick.Symbol, tick.Price * changePercentage);
    }
    //_ticks.Select((tick, i) =>
    //{
    //  var changePercentage = _itemToDrasticUpdate == i ? 1.2M : 1.1M;
    //  ticker.StockTick = new StockTick(tick.Symbol, tick.Price * changePercentage);
    //})
    //  .ToList();

    //_itemToDrasticUpdate++;
    //_itemToDrasticUpdate %= _ticks.Count();

  }
}