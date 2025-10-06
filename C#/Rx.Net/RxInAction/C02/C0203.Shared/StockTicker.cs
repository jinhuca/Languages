namespace C0203.Shared;

public sealed class StockTicker
{
  public event EventHandler<StockTick> StockTick = delegate { };

  public void Notify(StockTick tick)
  {
    StockTick(this, tick);
  }
}