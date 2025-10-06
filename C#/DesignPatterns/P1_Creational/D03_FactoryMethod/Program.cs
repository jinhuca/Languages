using static System.Console;

namespace D03FactoryMethod
{
  public class Program
  {
    public static void Main(string[] args)
    {
      WriteLine(Make(VehicleFactory.DrivingStyle.Economical, VehicleColor.Black));
    }

    public static IVehicle Make(VehicleFactory.DrivingStyle style, VehicleColor color)
    {
      VehicleFactory carFactory = new CarFactory();
      IVehicle car = carFactory.Build(style, color);
      return car;
    }

    public static IVehicle Make(Category cat, VehicleFactory.DrivingStyle style, VehicleColor color)
    {
      var factory = cat == Category.Car ? (VehicleFactory) new CarFactory() : new VanFactory();
      return factory.Build(style, color);
    }
  }
}
