namespace D09Decorator
{
  public abstract class AbstractVehicle : IVehicle
  {
    private IEngine engine;
    private VehicleColour colour;

    public AbstractVehicle(IEngine engine)
        : this(engine, VehicleColour.Unpainted)
    {
    }

    public AbstractVehicle(IEngine engine, VehicleColour colour)
    {
      this.engine = engine;
      this.colour = colour;
    }

    public virtual IEngine Engine
    {
      get
      {
        return engine;
      }
    }

    public virtual VehicleColour Colour
    {
      get
      {
        return colour;
      }
    }

    public virtual void Paint(VehicleColour colour)
    {
      this.colour = colour;
    }

    public abstract int Price { get; }

    public override string ToString()
    {
      return GetType().Name + " (" + engine + ", " + colour +
          ", price " + Price + ")";
    }

  }

}
