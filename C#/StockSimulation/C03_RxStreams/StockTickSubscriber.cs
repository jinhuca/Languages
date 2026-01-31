namespace C03_RxStreams;

internal class StockTickSubscriber : IObserver<Stock> {
  public void OnCompleted() {
    Console.WriteLine();
  }

  public void OnError(Exception error) {
    Console.WriteLine();
  }

  public void OnNext(Stock value) {
    Console.WriteLine(value.Symbol + " : " + value.Price);
  }
}