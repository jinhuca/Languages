namespace C0203.Shared;

/// <summary>
/// class holds the previous StockTick information, only used by event handling approach.
/// </summary>
/// <param name="symbol"></param>
/// <param name="price"></param>
public class StockInfo(string symbol, decimal price) {
  public string Symbol { get; set; } = symbol;
  public decimal PrevPrice { get; set; } = price;
}