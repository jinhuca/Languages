namespace D03FactoryMethod
{
  public abstract class AbstractCar : AbstractVehicle
  {
    protected AbstractCar(IEngine engine) : this(engine, VehicleColor.Unpainted) { }
    protected AbstractCar(IEngine engine, VehicleColor color) : base(engine, color) { }
  }
}
