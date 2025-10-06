using System;

namespace D10Facade
{
 public class Program
  {
    public static void Main(string[] args)
    {
      VehicleFacade facade = new VehicleFacade();
      facade.PrepareForSale(new Saloon(new StandardEngine(1300)));

      Console.Read();
    }
  }
}
