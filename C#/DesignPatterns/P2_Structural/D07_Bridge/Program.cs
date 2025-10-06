using System;

namespace D07Bridge
{
  public class Program
  {
    public static void Main()
    {
      IEngine engine = new StandardEngine(1300);
      AbstractDriverControls controls = new StandardControls(engine);
      controls.IgnitionOn();
      controls.Accelerate();

      // Can use a different engine without changing the driver controls
      IEngine turbo = new TurboEngine(1300);
      controls = new SportControls(turbo);
      controls.IgnitionOn();
      controls.Accelerate();

      Console.Read();
    }
  }
}
