namespace C03_RxStreams;

internal class C03Program {
  private static IObservable<Stock>? _observable;
  private static IObserver<Stock>? _observer;

  static void Main(string[] args) {

    _observer = new StockTickSubscriber();
    var source_ = new StockTickSource(_observer);
    _observable = source_._ticks;
    source_.Run();
    using var monitor_ = new StockMonitor(_observable, _observer);

    GC.KeepAlive(monitor_);
    Console.ReadLine();
  }
}