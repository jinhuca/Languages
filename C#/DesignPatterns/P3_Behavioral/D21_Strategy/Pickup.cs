namespace D21_Strategy
{
  public class Pickup : AbstractVan
  {

    public Pickup(IEngine engine)
        : this(engine, VehicleColour.Unpainted)
    {
    }

    public Pickup(IEngine engine, VehicleColour colour)
        : base(engine, colour)
    {
    }

  }
}
