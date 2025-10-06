using System;
using static System.Console;

namespace D18_Memento
{
  public class Program
  {
    public static void Main(string[] args)
    {
      approach1();
      approach2();
    }

    private static void approach1()
    {
      WriteLine("APPROACH 1");
      Speedometer1 speedo = new Speedometer1();

      speedo.CurrentSpeed = 50;
      speedo.CurrentSpeed = 100;
      WriteLine("Current speed: " + speedo.CurrentSpeed);
      WriteLine("Previous speed: " + speedo.previousSpeed);

      // Save the state of 'speedo'
      SpeedometerMemento1 memento = new SpeedometerMemento1(speedo);

      // Change the state of 'speed'
      speedo.CurrentSpeed = 80;
      WriteLine("After setting to 80...");
      WriteLine("Current speed: " + speedo.CurrentSpeed);
      WriteLine("Previous speed: " + speedo.previousSpeed);

      // Restore the state of 'speedo'
      WriteLine("Now restoring state...");
      memento.RestoreState();
      WriteLine("Current speed: " + speedo.CurrentSpeed);
      WriteLine("Previous speed: " + speedo.previousSpeed);
    }

    private static void approach2()
    {
      try
      {
        WriteLine("APPROACH 2");
        Speedometer2 speedo = new Speedometer2();

        speedo.CurrentSpeed = 50;
        speedo.PreviousSpeed = 100;
        WriteLine("Current speed: " + speedo.CurrentSpeed);
        WriteLine("Previous speed: " + speedo.PreviousSpeed);

        // Save the state of 'speedo'
        SpeedometerMemento2 memento = new SpeedometerMemento2(speedo);

        // Change the state of 'speed'
        speedo.CurrentSpeed = 80;
        WriteLine("After setting to 80...");
        WriteLine("Current speed: " + speedo.CurrentSpeed);
        WriteLine("Previous speed: " + speedo.PreviousSpeed);

        // Restore the state of 'speedo'
        WriteLine("Now restoring state...");
        speedo = memento.RestoreState();
        WriteLine("Current speed: " + speedo.CurrentSpeed);
        WriteLine("Previous speed: " + speedo.PreviousSpeed);
      }
      catch (Exception ex)
      {
        WriteLine(ex.ToString());
        Write(ex.StackTrace);
      }
    }
  }
}
