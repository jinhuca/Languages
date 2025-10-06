using System;
using static System.Console;

namespace D19_Observer
{
  public class SpeedMonitor
  {
    public const int SPEED_TO_ALERT = 70;

    public SpeedMonitor(Speedometer speedo)
    {
      speedo.ValueChanged += ValueHasChanged;
    }

    private void ValueHasChanged(Object sender, EventArgs e)
    {
      Speedometer speedo = (Speedometer)sender;
      if (speedo.CurrentSpeed > SPEED_TO_ALERT)
      {
        WriteLine($"** ALERT ** Driving too fast! ({speedo.CurrentSpeed})");

      }
      else
      {
        WriteLine($"... nice and steady ... ({speedo.CurrentSpeed})");
      }
    }
  }
}
