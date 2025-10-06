using static System.Console;

namespace D02Builder
{
  public class VanBuilder : VehicleBuilder
  {
    private AbstractVan _vanInProgress;

    public VanBuilder(AbstractVan van)
    {
      _vanInProgress = van;
    }

    public override void BuildBody()
    {
      WriteLine("Building van body.");
    }

    public override void BuildChassis()
    {
      WriteLine("Building van Chassis.");
    }

    public override void BuildReinforcedStorageArea()
    {
      WriteLine("Building van storage area.");
    }

    public override void BuildWindow()
    {
      WriteLine("Building van windows.");
    }

    public override IVehicle Vehicle => _vanInProgress;
  }
}
