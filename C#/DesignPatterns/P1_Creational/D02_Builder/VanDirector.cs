namespace D02Builder
{
  public class VanDirector : VehicleDirector
  {
    public override IVehicle Build(VehicleBuilder builder)
    {
      builder.BuildBody();
      builder.BuildChassis();
      builder.BuildReinforcedStorageArea();
      builder.BuildWindow();
      
      return builder.Vehicle;
    }
  }
}
