namespace D21_Strategy
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

  }
}
