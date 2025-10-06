namespace E03;

public class StockTickPublisher
{
  public event EventHandler<StockTick>? StockTickEvent;

  protected virtual void OnStockTick(StockTick stockTick)
  {
    StockTickEvent?.Invoke(this, stockTick);
  }

  private StockTick _tick;

  public StockTick StockTick
  {
    get => _tick;
    set
    {
      if (_tick == value) return;
      _tick = value;
      OnStockTick(_tick);
    }
  }
  /*
  private string _stockSymbol;

  public string StockSymbol
  {
    get => _stockSymbol;
    set
    {
      if(_stockSymbol != value)
      {
        _stockSymbol = value;
        OnStockTick(new StockTick(StockSymbol, StockPrice));
      }
    }
  }

  private decimal _stockPrice;

  //public StockTickPublisher(StockTick tick)
  //{
  //  _stockSymbol = tick.Symbol;
  //  _stockPrice = tick.Price;
  //}

  public decimal StockPrice
  {
    get => _stockPrice;
    set
    {
      if(_stockPrice != value)
      {
        _stockPrice = value;
        OnStockTick(new StockTick(StockSymbol, StockPrice));
      }
    }
  }

  */
}