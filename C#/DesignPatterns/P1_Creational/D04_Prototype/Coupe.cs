namespace D04Prototype
{
  public class Coupe : AbstractCar
  {
    public Coupe(IEngine engine) : this(engine, VehicleColor.UNPAINTED) { }
    public Coupe(IEngine engine, VehicleColor color) : base(engine, color) { }
  }
}
