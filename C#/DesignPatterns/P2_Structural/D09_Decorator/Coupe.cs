namespace D09Decorator
{
  public class Coupe : AbstractCar
  {

    public Coupe(IEngine engine)
        : this(engine, VehicleColour.Unpainted)
    {
    }

    public Coupe(IEngine engine, VehicleColour colour)
        : base(engine, colour)
    {
    }

    public override int Price => 7000;
  }
}
