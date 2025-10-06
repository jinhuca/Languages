namespace D09Decorator
{
  public class MetallicPaintedVehicle : AbstractVehicleOption
  {
    public MetallicPaintedVehicle(IVehicle vehicle)
        : base(vehicle)
    {
    }

    public override int Price => decoratedVehicle.Price + 750;
  }
}
