namespace C04_Streams;

internal struct StockDrasticChange {
  public string Symbol { get; set; }
  public decimal ChangeRatio { get; set; }
  public decimal OldPrice { get; set; }
  public decimal NewPrice { get; set; }
}