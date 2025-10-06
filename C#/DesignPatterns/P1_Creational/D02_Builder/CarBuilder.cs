using static System.Console;

namespace D02Builder
{
  public class CarBuilder : VehicleBuilder
  {
    private AbstractCar _carInProgress;

    public CarBuilder(AbstractCar car)
    {
      _carInProgress = car;
    }

    public override void BuildBody()
    {
      WriteLine("Building car body.");
    }

    public override void BuildBoot()
    {
      WriteLine("Building car boot.");
    }

    public override void BuildChassis()
    {
      WriteLine("Building car chassis.");
    }

    public override void BuildPassengerArea()
    {
      WriteLine("Building car passenger area.");
    }

    public override void BuildReinforcedStorageArea()
    {
      WriteLine("Building car windows.");
    }

    public override IVehicle Vehicle => _carInProgress;
  }
}
