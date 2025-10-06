namespace D03FactoryMethod
{
  public abstract class VehicleFactory
  {
    public enum DrivingStyle { Economical, Midrange, Powerful }

    public virtual IVehicle Build(DrivingStyle style, VehicleColor color)
    {
      IVehicle v = SelectVehicle(style);
      v.Paint(color);
      return v;
    }

    // This is the "factory method"
    protected internal abstract IVehicle SelectVehicle(DrivingStyle style);
  }
}
