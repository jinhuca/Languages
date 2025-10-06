namespace D06Adapter
{
  public interface IVehicle
  {
    IEngine Engine { get; }
    VehicleColor Color { get; }
    void Paint(VehicleColor color);
  }
}
