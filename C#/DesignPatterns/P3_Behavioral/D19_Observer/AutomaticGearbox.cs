using System;
using static System.Console;

namespace D19_Observer
{
  public class AutomaticGearbox
  {
    public AutomaticGearbox(Speedometer speedo)
    {
      speedo.ValueChanged += ValueHasChanged;
    }

    private void ValueHasChanged(Object sender, EventArgs e)
    {
      Speedometer speedo = (Speedometer)sender;
      if (speedo.CurrentSpeed <= 10)
      {
        WriteLine("Now in first gear");

      }
      else if (speedo.CurrentSpeed <= 20)
      {
        WriteLine("Now in second gear");

      }
      else if (speedo.CurrentSpeed <= 30)
      {
        WriteLine("Now in third gear");

      }
      else
      {
        WriteLine("Now in fourth gear");
      }
    }
  }
}
