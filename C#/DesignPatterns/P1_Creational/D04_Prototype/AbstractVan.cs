namespace D04Prototype
{
  public abstract class AbstractVan : AbstractVehicle
  {
    protected AbstractVan(IEngine engine) : this(engine, VehicleColor.UNPAINTED) { }
    protected AbstractVan(IEngine engine, VehicleColor color) : base(engine, color) { }
  }
}
