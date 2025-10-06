using System;

namespace D21_Strategy
{
  public class Program
  {
    public static void Main(string[] args)
    {
      AbstractCar myCar = new Sport(new StandardEngine(2000));
      myCar.Speed = 20;
      myCar.Speed = 40;

      Console.WriteLine("Switching on sports mode gearbox...");
      myCar.IGearboxStrategy = new SportGearboxStrategy();
      myCar.Speed = 20;
      myCar.Speed = 40;

      Console.Read();
    }
  }
}
