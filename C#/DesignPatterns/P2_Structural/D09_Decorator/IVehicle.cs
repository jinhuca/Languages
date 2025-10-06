namespace D09Decorator
{
  public interface IVehicle
  {
    IEngine Engine { get; }
    VehicleColour Colour { get; }
    void Paint(VehicleColour colour);

    int Price { get; }
  }
}
