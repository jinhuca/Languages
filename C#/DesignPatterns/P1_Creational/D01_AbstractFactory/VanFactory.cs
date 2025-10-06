namespace D01AbstractFactory
{
  public class VanFactory : AbstractVehicleFactory
  {
    public override IBody CreateBody()
    {
      return new VanBody();
    }

    public override IChassis CreateChassis()
    {
      return new VanChassis();
    }

    public override IGlassware CreateGlassware()
    {
      return new VanGlassware();
    }
  }
}
