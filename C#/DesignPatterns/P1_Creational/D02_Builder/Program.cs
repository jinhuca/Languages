using static System.Console;

namespace D02Builder
{
  public class Program
  {
    public static void Main(string[] args)
    {
      AbstractCar car = new Saloon(new StandardEngine(1300));
      VehicleBuilder builder = new CarBuilder(car);
      VehicleDirector director = new CarDirector();
      IVehicle v = director.Build(builder);
      WriteLine(v);
      Read();
    }
  }
}
