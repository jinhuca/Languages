namespace D09Decorator
{
  public class AirConditionedVehicle : AbstractVehicleOption
  {
    public AirConditionedVehicle(IVehicle vehicle)
        : base(vehicle)
    {
    }

    public override int Price
    {
      get
      {
        return decoratedVehicle.Price + 600;
      }
    }

    public virtual int Temperature
    {
      set
      {
        // code to set the temperature...
      }
    }
  }
}
