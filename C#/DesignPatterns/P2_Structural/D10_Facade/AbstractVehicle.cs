using static System.Console;

namespace D10Facade
{
  public abstract class AbstractVehicle : IVehicle
  {
    private IEngine engine;
    private VehicleColor _color;

    protected AbstractVehicle(IEngine engine)
        : this(engine, VehicleColor.Unpainted)
    {
    }

    protected AbstractVehicle(IEngine engine, VehicleColor color)
    {
      this.engine = engine;
      _color = color;
    }

    public virtual IEngine Engine => engine;

    public virtual VehicleColor Color => _color;

    public virtual void Paint(VehicleColor color)
    {
      _color = color;
    }


    public virtual void CleanInterior()
    {
      WriteLine("Cleaning interior...");
    }

    public virtual void CleanExteriorBody()
    {
      WriteLine("Cleaning exterior body...");
    }

    public virtual void PolishWindows()
    {
      WriteLine("Polishing windows...");
    }

    public virtual void TakeForTestDrive()
    {
      WriteLine("Taking for test drive...");
    }


    public override string ToString() => GetType().Name + " (" + engine + ", " + _color + ")";
  }

}
