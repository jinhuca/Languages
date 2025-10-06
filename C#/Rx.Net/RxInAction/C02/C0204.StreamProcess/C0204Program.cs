using System.Reactive;
using System.Reactive.Linq;

namespace C0204.StreamProcess;

internal class C0204Program
{
  static void Main(string[] args)
  {
    //test();
    Test2();
  }

  static void test()
  {
    IObserver<StockTick> observer = Observer.Create<StockTick>(
      stock =>
      {
        Console.WriteLine($"{stock.Symbol} = {stock.Price}");
      }
    );

    var service = new StockService();
    //service_.StockObservable.Subscribe(
    //  stock =>
    //  {
    //    Console.WriteLine($"{stock.Symbol} = {stock.Price}");
    //  });
    service.Run(observer);
    Console.ReadLine();
  }

  static void Test2()
  {
    const decimal maxChangeRatio = 0.1m;
    var service = new StockService();

    IObservable<StockTick> stockObservable_ = service.StockObservable;

    //IObservable<DrasticChange> drasticChanges_ =
    //  from tick in stockObservable_
    //  group tick by tick.Symbol
    //  into company
    //  from tickPair in company.Buffer(2, 1)
    //  let changeRatio = Math.Abs((decimal)((tickPair[1].Price - tickPair[0].Price) / tickPair[0].Price))
    //  where changeRatio > maxChangeRatio
    //  select new DrasticChange
    //  {
    //    Symbol = company.Key,
    //    ChangeRatio = changeRatio,
    //    OldPrice = tickPair[0].Price,
    //    NewPrice = tickPair[1].Price
    //  };

    stockObservable_.Subscribe(
      stock => Console.WriteLine($"{stock.Symbol} = {stock.Price}"));
    Console.ReadLine();
  }
}