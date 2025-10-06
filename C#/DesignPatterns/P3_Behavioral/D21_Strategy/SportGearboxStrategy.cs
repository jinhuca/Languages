using System;

namespace D21_Strategy
{
  public class SportGearboxStrategy : IGearboxStrategy
  {
    public virtual void EnsureCorrectGear(IEngine engine, int speed)
    {
      int engineSize = engine.Size;
      bool turbo = engine.Turbo;

      // Some complicated code to determine correct gear
      // setting based on engineSize, turbo & speed, etc.
      // ... omitted ...

      Console.WriteLine("Working out correct gear at "
        + speed + "mph for a SPORT gearbox");
    }
  }
}
