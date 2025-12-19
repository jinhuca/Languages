// See https://aka.ms/new-console-template for more information

using C01_EventHandling;

file class C01_Program {
  private static StockTick? _stockTick;

  public static void Main() {
    _stockTick = new StockTick();
    var stockNotifier_ = new StockTickMonitor(_stockTick);
    StockTickGenerator generator_ = new StockTickGenerator(_stockTick);
    generator_.Run();
    Console.ReadLine();
  }
}
