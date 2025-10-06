namespace D04Prototype
{
  public abstract class AbstractCar : AbstractVehicle
  {
    protected AbstractCar(IEngine engine) : this(engine, VehicleColor.UNPAINTED) { }
    protected AbstractCar(IEngine engine, VehicleColor color) : base(engine, color) { }
  }
}
