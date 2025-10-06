namespace D21_Strategy
{
  public interface IVehicle
  {
    IEngine Engine { get; }
    VehicleColour Colour { get; }
    void Paint(VehicleColour colour);
  }
}
