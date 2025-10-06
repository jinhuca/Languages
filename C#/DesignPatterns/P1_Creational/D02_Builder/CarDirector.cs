namespace D02Builder
{
  public class CarDirector : VehicleDirector
  {
    public override IVehicle Build(VehicleBuilder builder)
    {
      builder.BuildBody();
      builder.BuildBoot();
      builder.BuildChassis();
      builder.BuildPassengerArea();
      builder.BuildWindow();

      return builder.Vehicle;
    }
  }
}
