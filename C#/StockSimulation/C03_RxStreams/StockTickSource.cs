using System;
using System.Collections.Generic;
using System.Reactive;
using System.Reactive.Disposables;
using System.Reactive.Linq;
using System.Text;

namespace C03_RxStreams;

internal class StockTickSource(IObserver<Stock> observer) {
  private IObserver<Stock> _observer = observer;

  public void Run() {
    Task.Run(() => {
      while (true) {
        Thread.Sleep(1000);
        UpdatePrices();

        //PushUpdates(observer);
        //PrintPrices();
      }
    });
  }

  // ReSharper disable once FunctionNeverReturns

  public IObservable<Stock> _ticks = new List<Stock>()
  {
 new() { Symbol = "MSFT", Price = 53.12M },
    new () { Symbol = "INTC", Price = 32.38M },
    new () { Symbol = "ORCL", Price = 41.27M },
    new () { Symbol = "CSCO", Price = 28.65M }
  }.ToObservable();


  private void UpdatePrices() {

    Random rand_ = new();
    var c1_ = rand_.Next(0, 30) * 0.01M;
    var c2_ = rand_.Next(0, 13) * -0.01M;

    foreach (Stock stock_ in _ticks) {
      stock_.Price = decimal.Round(stock_.Price * (rand_.Next(0, 10) % 2 == 0 ? 1 + c1_ : 1 + c2_), 2);
      _observer.OnNext(stock_);
    }
  }

  private void PrintPrices() {
    Console.WriteLine("==Current stock prices:");
    foreach (var tick_ in _ticks) {
      Console.WriteLine(tick_.Symbol + " : " + tick_.Price);
    }
    Console.WriteLine();
  }
}