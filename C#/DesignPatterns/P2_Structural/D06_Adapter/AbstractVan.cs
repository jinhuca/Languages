namespace D06Adapter
{
  public abstract class AbstractVan : AbstractVehicle
  {
    protected AbstractVan(IEngine engine) : this(engine, VehicleColor.Unpainted) { }
    protected AbstractVan(IEngine engine, VehicleColor color) : base(engine, color) { }
  }
}
