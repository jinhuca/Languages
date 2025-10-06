using System;

namespace D24_NullObject
{
  public class BrakeFluidLight : IWarningLight
  {
    public virtual void On()
    {
      Console.WriteLine("Brake fluid light ON");
    }

    public virtual void Off()
    {
      Console.WriteLine("Brake fluid light OFF");
    }
  }
}
