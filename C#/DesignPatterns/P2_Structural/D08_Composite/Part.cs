namespace D08Composite
{
  public class Part : Item
  {
    public Part(string description, int cost) : base(description, cost) { }

    // Empty implementations for unit parts...
    public override void AddItem(Item item) { }

    public override void RemoveItem(Item item) { }

    public override Item[] Items => new Item[0];
  }
}
