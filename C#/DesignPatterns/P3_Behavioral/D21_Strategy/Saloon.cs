namespace D21_Strategy
{
  public class Saloon : AbstractCar
  {

    public Saloon(IEngine engine)
        : this(engine, VehicleColour.Unpainted)
    {
    }

    public Saloon(IEngine engine, VehicleColour colour)
        : base(engine, colour)
    {
    }

  }
}
