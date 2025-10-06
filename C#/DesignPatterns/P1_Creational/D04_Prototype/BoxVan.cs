namespace D04Prototype
{
  public class BoxVan : AbstractVan
  {

    public BoxVan(IEngine engine)
        : this(engine, VehicleColor.UNPAINTED)
    {
    }

    public BoxVan(IEngine engine, VehicleColor color)
        : base(engine, color)
    {
    }

  }
}
