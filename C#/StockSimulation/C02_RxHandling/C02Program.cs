using C02_RxHandling;
using static System.Console;

public class C02Program {
  private static StockTick? _stockTick;

  public static void Main() {
    _stockTick = new StockTick();
    using var stockNotifier_ = new StockTickMonitorRx(_stockTick);
    StockTickGenerator generator_ = new StockTickGenerator(_stockTick);
    generator_.Run();

    GC.KeepAlive(stockNotifier_);
    ReadLine();
  }
}
