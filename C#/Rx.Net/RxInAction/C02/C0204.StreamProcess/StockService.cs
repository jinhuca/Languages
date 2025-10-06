using System;
using System.Collections.Concurrent;
using System.Collections.Generic;
using System.Linq;
using System.Reactive;
using System.Reactive.Linq;
using System.Text;
using System.Threading.Tasks;

namespace C0204.StreamProcess;

public class StockService
{
  private BlockingCollection<StockTick> _stockTickList = new BlockingCollection<StockTick>();
  
  //{
  //  StockTick = new StockTick { Symbol = "AAPL", Price = 88.2M },
  //  StockTick1 = new StockTick { Symbol = "BSX", Price = 93.2M },
  //  StockTick2 = new StockTick { Symbol = "INTC", Price = 34M },
  //  StockTick3 = new StockTick { Symbol = "MSFT", Price = 53M }
  //};

  

  private int _stockItemToUpdate;

  public StockService()
  {
    InitializeStock();
    StockObservable = _stockTickList.ToObservable();
  }

  private void InitializeStock()
  {
    _stockTickList.TryAdd(new StockTick { Symbol = "AAPL", Price = 88.2M });
    _stockTickList.TryAdd(new StockTick { Symbol = "BSX", Price = 93.2M });
    _stockTickList.TryAdd(new StockTick { Symbol = "INTC", Price = 34M });
    _stockTickList.TryAdd(new StockTick { Symbol = "MSFT", Price = 53M });
  }

  public void Run(IObserver<StockTick> observer)
  {
    Task.Run(() =>
    {
      while (true)
      {
        UpdatePrices(observer);
        //PublishUpdates(observer);
        Thread.Sleep(TimeSpan.FromSeconds(1));
      }
    });
  }

  private void PublishUpdates(IObserver<StockTick> observer)
  {
    _stockTickList.Subscribe(observer);
  }

  private void UpdatePrices(IObserver<StockTick> observer)
  {
    StockObservable
      .Select((stock, item) =>
      {
        var changePercentage = _stockItemToUpdate == item ? 1.23M : 0.76M;
        return new StockTick
        {
          Symbol = stock.Symbol, Price = stock.Price * changePercentage
        };
      })
      .Subscribe(
        stock => { observer.OnNext(stock); },
        ex => { observer.OnError(new Exception()); },
        () => { observer.OnCompleted(); }
      );
        
    _stockItemToUpdate++;
    _stockItemToUpdate %= _stockTickList.Count();
  }

  public IObservable<StockTick> StockObservable { get; set; }
}