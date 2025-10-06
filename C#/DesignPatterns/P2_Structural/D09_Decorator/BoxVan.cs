namespace D09Decorator
{
  public class BoxVan : AbstractVan
  {

    public BoxVan(IEngine engine)
        : this(engine, VehicleColour.Unpainted)
    {
    }

    public BoxVan(IEngine engine, VehicleColour colour)
        : base(engine, colour)
    {
    }

    public override int Price => 10000;
  }
}
