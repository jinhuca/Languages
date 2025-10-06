using System;
using static System.Console;

namespace D24_NullObject
{
  public class OilLevelLight : IWarningLight
  {
    public virtual void On()
    {
      WriteLine("Oil level light ON");
    }

    public virtual void Off()
    {
      WriteLine("Oil level light OFF");
    }
  }
}
