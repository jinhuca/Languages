using System;

namespace D25_SimpleFactory
{
  public class Program
  {
    public static void Main(string[] args)
    {
      // Create an automatic gearbox
      Gearbox auto = GearboxFactory.Create(GearboxFactory.Type.Automatic);

      // Create a manual gearbox
      Gearbox manual = GearboxFactory.Create(GearboxFactory.Type.Manual);
    }
  }
}
