using static System.Console;

namespace D09Decorator
{
  class Program
  {
    static void Main(string[] args)
    {
      // Create a blue saloon car
      IVehicle myCar = new Saloon(new StandardEngine(1300));
      myCar.Paint(VehicleColour.Blue);
      WriteLine(myCar);

      // Add air-conditioning to the car...
      myCar = new AirConditionedVehicle(myCar);
      WriteLine(myCar);

      // Now add alloy wheels...
      myCar = new AlloyWheeledVehicle(myCar);
      WriteLine(myCar);

      // Now add leather seats...
      myCar = new LeatherSeatedVehicle(myCar);
      WriteLine(myCar);

      // Now add metallic paint...
      myCar = new MetallicPaintedVehicle(myCar);
      WriteLine(myCar);

      // Now add satellite navigation
      myCar = new SatNavVehicle(myCar);
      WriteLine(myCar);
    }
  }
}
