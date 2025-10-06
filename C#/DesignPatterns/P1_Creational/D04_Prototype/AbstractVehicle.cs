namespace D04Prototype
{
  public abstract class AbstractVehicle : IVehicle
  {
    private readonly IEngine _engine;
    private VehicleColor _color;

    protected AbstractVehicle(IEngine engine) : this(engine, VehicleColor.UNPAINTED)
    {
    }

    protected AbstractVehicle(IEngine engine, VehicleColor color)
    {
      _engine = engine;
      _color = color;
      // ... followed by lots of time-consuming stuff
    }

    public virtual IEngine Engine => _engine;

    public virtual VehicleColor Color => _color;

    public virtual void Paint(VehicleColor color)
    {
      _color = color;
    }

    public virtual object Clone() => MemberwiseClone();

    public override string ToString() => GetType().Name + " (" + _engine + ", " + _color + ")";
  }
}
