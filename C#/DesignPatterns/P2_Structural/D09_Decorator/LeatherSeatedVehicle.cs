namespace D09Decorator
{
  public class LeatherSeatedVehicle : AbstractVehicleOption
  {
    public LeatherSeatedVehicle(IVehicle vehicle)
        : base(vehicle)
    {
    }

    public override int Price => decoratedVehicle.Price + 1200;
  }
}
