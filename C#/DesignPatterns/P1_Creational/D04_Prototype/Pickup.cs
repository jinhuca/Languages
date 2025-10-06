namespace D04Prototype
{
  public class Pickup : AbstractVan
  {
    public Pickup(IEngine engine) : this(engine, VehicleColor.UNPAINTED) { }
    public Pickup(IEngine engine, VehicleColor color) : base(engine, color) { }
  }
}
