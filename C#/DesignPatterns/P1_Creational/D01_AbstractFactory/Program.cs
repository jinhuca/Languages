using D01AbstractFactory;
using static System.Console;

namespace C01AbstractFactory
{
  public class Program
  {
    private static string whatToMake = "car";    // or "van"

    private static AbstractVehicleFactory factory = null;

    public static void Main(string[] args)
    {
      // Create the correct 'factory' 
      factory = whatToMake.Equals("car") ? new CarFactory() : new VanFactory();

      // Create the vehicle's component parts ...
      // These will either be all car parts or all van parts.
      IBody vehicleBody = factory.CreateBody();
      IChassis vehicleChassis = factory.CreateChassis();
      IGlassware vehicleGlassware = factory.CreateGlassware();

      // Show what we've created ...
      WriteLine(vehicleBody.BodyParts);
      WriteLine(vehicleChassis.ChassisParts);
      WriteLine(vehicleGlassware.GlasswareParts);
    }
  }
}
