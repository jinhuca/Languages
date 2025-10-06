namespace D01AbstractFactory
{
  public class Saloon : AbstractCar
  {
    public Saloon(IEngine engine) : this(engine, VehicleColor.Unpainted) { }

    public Saloon(IEngine engine, VehicleColor color) : base(engine, color) { }
  }
}
