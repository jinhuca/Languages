namespace D03FactoryMethod
{
  public class VanFactory : VehicleFactory
  {
    protected internal override IVehicle SelectVehicle(DrivingStyle style)
    {
      return style is DrivingStyle.Economical or DrivingStyle.Midrange
        ? (IVehicle)new Pickup(new StandardEngine(2200))
        : new BoxVan(new TurboEngine(2500));
    }
  }
}
