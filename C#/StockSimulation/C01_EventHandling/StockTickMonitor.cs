using static System.Console;

namespace C01_EventHandling;

internal class StockTickMonitor : IDisposable {
  private readonly Lock _tickLocker = new();
  private readonly StockTick? _stockTick;
  private readonly Dictionary<string, Stock> _stocks = new();

  public StockTickMonitor(StockTick stockTick) {
    _stockTick = stockTick;
    _stockTick.StockPriceChanged += OnStockPriceChanged;
  }

  public void Dispose() {
    _stockTick?.StockPriceChanged -= OnStockPriceChanged;
    _stocks.Clear();
  }

  private void OnStockPriceChanged(object? sender, Stock stock) {
    var stockSymbol_ = stock.Symbol;
    lock (_tickLocker) {
      var isStockInfoExists_ = _stocks.TryGetValue(stockSymbol_ ?? string.Empty, out var stockInfo_);
      if (isStockInfoExists_)
      {
        if (stockInfo_ == null) return;
        var priceDiff_ = Math.Abs(stock.Price - stockInfo_.Price);
        var changeRatio_ = priceDiff_ / stockInfo_.Price;
        if (changeRatio_ < maximum_change_ratio) return;
        ForegroundColor = ConsoleColor.Blue;
        WriteLine($"Stock: {stock.Symbol}, Old Price: {stockInfo_.Price:F2}, New Price: {stock.Price:F2}, Change Ratio: {changeRatio_:P2}");
        ResetColor();
        _stocks[stockSymbol_ ?? string.Empty] = stock;
      }
      else {
        ForegroundColor = ConsoleColor.Red;
        WriteLine("add stock - " + stockSymbol_);
        ResetColor();
        _stocks.Add(stockSymbol_ ?? string.Empty, stock);
      }
    }
  }

  private const decimal maximum_change_ratio = 0.1m;
}