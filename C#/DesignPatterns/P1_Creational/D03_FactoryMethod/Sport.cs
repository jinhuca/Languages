namespace D03FactoryMethod
{
  public class Sport : AbstractCar
  {
    public Sport(IEngine engine) : this(engine, VehicleColor.Unpainted) { }
    public Sport(IEngine engine, VehicleColor color) : base(engine, color) { }
  }
}
