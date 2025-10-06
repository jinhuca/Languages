namespace D06Adapter
{
  public abstract class AbstractVehicle : IVehicle
  {
    protected AbstractVehicle(IEngine engine) : this(engine, VehicleColor.Unpainted) { }

    protected AbstractVehicle(IEngine engine, VehicleColor color)
    {
      Engine = engine;
      Color = color;
    }

    public IEngine Engine { get; private set; }

    public VehicleColor Color { get; private set; }

    public void Paint(VehicleColor color)
    {
      Color = color;
    }

    public override string ToString() => GetType().Name + " (" + Engine + ", " + Color + ")";
  }
}
