namespace E03;

public record StockTick(string Symbol, decimal Price)
{
  public string Symbol { get; } = Symbol;
  public decimal Price { get; } = Price;

  public virtual bool Equals(StockTick? other)
  {
    if(other==null)
      return false;
    return Symbol==other.Symbol&&Price==other.Price;
  }

  public override int GetHashCode()
  {
    return HashCode.Combine(Symbol, Price);
  }
}