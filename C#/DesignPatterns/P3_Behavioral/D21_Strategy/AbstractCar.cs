namespace D21_Strategy
{
  public abstract class AbstractCar : AbstractVehicle
  {
    private IGearboxStrategy gearboxStrategy;

    public AbstractCar(IEngine engine)
        : this(engine, VehicleColour.Unpainted)
    {
    }

    public AbstractCar(IEngine engine, VehicleColour colour)
        : base(engine, colour)
    {
      // Starts in standard gearbox mode (more economical)
      gearboxStrategy = new StandardGearboxStrategy();
    }

    // Allow the gearbox strategy to be changed...
    public virtual IGearboxStrategy IGearboxStrategy
    {
      set
      {
        this.gearboxStrategy = value;
      }
      get
      {
        return gearboxStrategy;
      }
    }

    public virtual int Speed
    {
      set
      {
        // Delegate to strategy in effect...
        gearboxStrategy.EnsureCorrectGear(Engine, value);
      }
    }

  }
}
