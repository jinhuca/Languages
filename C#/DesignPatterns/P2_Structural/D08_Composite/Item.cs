namespace D08Composite
{
  public abstract class Item
  {
    private readonly string _description;
    private readonly int _cost;

    protected Item(string description, int cost)
    {
      _description = description;
      _cost = cost;
    }

    public virtual string Description => _description;
    public virtual int Cost => _cost;
    public abstract void AddItem(Item item);
    public abstract void RemoveItem(Item item);
    public abstract Item[] Items { get; }
    public override string ToString() => _description + " (cost " + Cost + ")";
  }
}
