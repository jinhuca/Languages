using System;

namespace D04Prototype
{
  public interface IVehicle : ICloneable
  {
    IEngine Engine { get; }
    VehicleColor Color { get; }
    void Paint(VehicleColor color);
  }
}
