using C0203.Shared;
using static System.Console;

namespace C0201.EventHandling;

sealed class StockMonitorViaEvent : IDisposable {
  private readonly object _stockTickLocker = new();
  private readonly StockTicker? _ticker;
  private readonly Dictionary<string, StockInfo> _stockInfos = new();

  public StockMonitorViaEvent(StockTicker? ticker) {
    _ticker = ticker;
    if (ticker != null) ticker.StockTick += OnStockTick;
  }

  public void Dispose() {
    if(_ticker != null) _ticker.StockTick -= OnStockTick;
    _stockInfos.Clear();
  }

  private void OnStockTick(object sender, StockTick stockTick) {
    const decimal maxChangeRatio = 0.1m;
    var quoteSymbol = stockTick.Symbol;
    lock(_stockTickLocker) {
      var stockInfoExists = _stockInfos.TryGetValue(
                                            quoteSymbol, out var stockInfo);
      if(stockInfoExists) {
        if(stockInfo != null) {
          var priceDiff = stockTick.Price - stockInfo.PrevPrice;
          var changeRatio = Math.Abs(priceDiff/stockInfo.PrevPrice);
          if(changeRatio > maxChangeRatio) {
            WriteLine($"Stock: {quoteSymbol} has changed with " +
                      $"{changeRatio} ratio, Old Price: " +
                      $"{stockInfo.PrevPrice:#.##} New Price: " +
                      $"{stockTick.Price:#.##}");
          }
        }
        _stockInfos[quoteSymbol].PrevPrice = stockTick.Price;
      }
      else {
        _stockInfos[quoteSymbol] = new StockInfo(quoteSymbol, stockTick.Price);
      }
    }
  }
}