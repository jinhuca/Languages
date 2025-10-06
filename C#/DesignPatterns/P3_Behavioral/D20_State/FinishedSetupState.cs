using System;

namespace D20_State
{
  public class FinishedSetupState : ClockSetupState
  {
    private ClockSetup clockSetup;

    public FinishedSetupState(ClockSetup clockSetup)
    {
      this.clockSetup = clockSetup;
    }

    public virtual void PreviousValue()
    {
      Console.WriteLine("Ignored...");
    }

    public virtual void NextValue()
    {
      Console.WriteLine("Ignored...");
    }

    public virtual void SelectValue()
    {
      DateTime selectedDate = clockSetup.SelectedDate;
      Console.WriteLine("Date set to: " + selectedDate);
    }

    public virtual string Instructions
    {
      get
      {
        return "Press knob to view selected date...";
      }
    }

    public virtual int SelectedValue
    {
      get
      {
        throw new System.NotSupportedException("Clock setup finished");
      }
    }

  }
}
