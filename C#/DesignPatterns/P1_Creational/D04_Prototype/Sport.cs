namespace D04Prototype
{
  public class Sport : AbstractCar
  {
    public Sport(IEngine engine) : this(engine, VehicleColor.UNPAINTED) { }
    public Sport(IEngine engine, VehicleColor color) : base(engine, color) { }
  }
}
