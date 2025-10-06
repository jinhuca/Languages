namespace D04Prototype
{
  public class Saloon : AbstractCar
  {
    public Saloon(IEngine engine) : this(engine, VehicleColor.UNPAINTED) { }
    public Saloon(IEngine engine, VehicleColor color) : base(engine, color) { }
  }
}
