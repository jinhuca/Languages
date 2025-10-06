namespace D09Decorator
{
  public class AlloyWheeledVehicle : AbstractVehicleOption
  {
    public AlloyWheeledVehicle(IVehicle vehicle)
        : base(vehicle)
    {
    }

    public override int Price => decoratedVehicle.Price + 250;
  }
}
