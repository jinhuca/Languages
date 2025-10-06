namespace D03FactoryMethod
{
  public class CarFactory : VehicleFactory
  {
    protected internal override IVehicle SelectVehicle(DrivingStyle style)
    {
      return style switch
      {
        DrivingStyle.Economical => new Saloon(new StandardEngine(1300)),
        DrivingStyle.Midrange => new Coupe(new StandardEngine(1600)),
        _ => new Sport(new TurboEngine(2000))
      };
    }
  }
}
